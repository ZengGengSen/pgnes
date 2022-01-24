#ifndef PGNES_STDOUT_LOGGER_H
#define PGNES_STDOUT_LOGGER_H

#include "abstract_logger.h"
#include <spdlog/sinks/stdout_sinks.h>

class StdOutLogger : public AbstractLogger {
public:
    explicit StdOutLogger(std::string name = "stdOutLogger") : AbstractLogger(std::move(name)) {}

    void createLogger() override {
        logger = spdlog::stdout_logger_mt(loggerName);
    }
};

#endif //PGNES_STDOUT_LOGGER_H
