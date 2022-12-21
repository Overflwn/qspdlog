#pragma once

#include <QToolBar>

class QSpdLogToolBar : public QToolBar {
  Q_OBJECT

public:
  struct FilteringSettings {
    QString text;
    bool isRegularExpression;
    bool isCaseSensitive;
  };

  enum AutoScrollPolicy {
    AutoScrollPolicyDisabled = 0,
    AutoScrollPolicyEnabled = 1,
    AutoScrollPolicyEnabledIfBottom = 2
  };

public:
  QSpdLogToolBar(QWidget *parent = nullptr);
  ~QSpdLogToolBar();

  FilteringSettings filteringSettings() const;
  void checkInputValidity();

signals:
  void filterChanged();
  void autoScrollPolicyChanged(int index);

private:
  QWidget *_filterWidget;
  QAction *_caseAction;
  QAction *_regexAction;
};