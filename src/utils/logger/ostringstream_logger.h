#ifndef PGNES_OSTRINGSTREAM_LOGGER_H
#define PGNES_OSTRINGSTREAM_LOGGER_H

#include "abstract_logger.h"
#include <spdlog/sinks/ostream_sink.h>

class OStringStreamLogger : public AbstractLogger {
public:
    explicit OStringStreamLogger(std::ostringstream &oss, std::string name = "oStringStreamLogger") :
            AbstractLogger(std::move(name)), oStringStream(oss) {}

    void createLogger() override {
        logger = std::make_shared<spdlog::logger>(
                loggerName,
                std::make_shared<spdlog::sinks::ostream_sink_mt>(oStringStream));
    }

private:
    std::ostringstream &oStringStream;
};

#endif //PGNES_OSTRINGSTREAM_LOGGER_H
