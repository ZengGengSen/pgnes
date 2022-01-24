#ifndef PGNES_STDERR_LOGGER_H
#define PGNES_STDERR_LOGGER_H

#include "abstract_logger.h"
#include <spdlog/sinks/stdout_sinks.h>

class StdErrLogger : public AbstractLogger {
public:
    explicit StdErrLogger(std::string name = "stdErrLogger") : AbstractLogger(std::move(name)) {}
    void createLogger() override {
        logger = spdlog::stderr_logger_mt(loggerName);
    }
};

#endif //PGNES_STDERR_LOGGER_H
