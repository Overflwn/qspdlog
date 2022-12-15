#pragma once

#include "qspdlog_model.hpp"
#include <spdlog/sinks/base_sink.h>

template <typename Mutex>
class qt_logger_sink : public spdlog::sinks::base_sink<Mutex> {
public:
  qt_logger_sink(QSpdLogModel &model) : _model(model) {}

protected:
  void sink_it_(const spdlog::details::log_msg &msg) override {
    _model.addEntry(
        {msg.time.time_since_epoch(), msg.level, fmt::to_string(msg.payload)});
  }

  void flush_() override {}

private:
  QSpdLogModel &_model;
};

#include <mutex>

#include "spdlog/details/null_mutex.h"
using qt_logger_sink_mt = qt_logger_sink<std::mutex>;
using qt_logger_sink_st = qt_logger_sink<spdlog::details::null_mutex>;