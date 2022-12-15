#pragma once

#include <qabstractitemmodel>

class QSpdLogModel : public QAbstractTableModel {
public:
  Q_OBJECT
public:
  struct entry_t {
    std::chrono::duration<double> time;
    int level;
    std::string message;
  };

public:
  QSpdLogModel(QObject *parent = nullptr);
  ~QSpdLogModel() override = default;

  void addEntry(entry_t entry);

#pragma region QAbstractTableModel
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;
#pragma endregion

private:
  std::vector<entry_t> _items;
};