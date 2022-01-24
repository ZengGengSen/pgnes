#ifndef PGNES_MULTI_LOGGER_H
#define PGNES_MULTI_LOGGER_H

#include "abstract_logger.h"

class MultiLogger : public AbstractLogger {
public:
    explicit MultiLogger(
            std::vector<spdlog::sink_ptr> ss,
            std::string name = "MultiLogger") :
            AbstractLogger(std::move(name)), sinks(std::move(ss)) {}

    void createLogger() override {
        logger = std::make_shared<spdlog::logger>(loggerName, sinks.begin(), sinks.end());
    }

protected:
    std::vector<spdlog::sink_ptr> sinks;
};

#endif //PGNES_MULTI_LOGGER_H
