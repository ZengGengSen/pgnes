#ifndef PGNES_LOGGER_FACTORY_H
#define PGNES_LOGGER_FACTORY_H

#include "stdout_logger.h"
#include "stderr_logger.h"
#include "file_logger.h"
#include "ostringstream_logger.h"
#include "multi_logger.h"

enum LoggerType {
    LT_STDOUT = 0x01,
    LT_STDERR = 0x02,
    LT_FILE = 0x04,
    LT_OSS = 0x08,
    LT_Multi = 0x0F
};

class LoggerFactory {
public:
    std::shared_ptr<AbstractLogger> getLogger(uint8_t loggerType) {
        std::vector<spdlog::sink_ptr> sinks{};

        if (loggerType == LoggerType::LT_STDOUT) {
            return std::make_shared<StdOutLogger>();
        } else if (loggerType == LoggerType::LT_STDERR) {
            return std::make_shared<StdErrLogger>();
        } else if (loggerType == LoggerType::LT_FILE) {
            return std::make_shared<FileLogger>();
        } else if (loggerType == LoggerType::LT_OSS) {
            return std::make_shared<OStringStreamLogger>(streamLogger);
        }
    }
private:
    OStringStreamLogger streamLogger;
};

#endif //PGNES_LOGGER_FACTORY_H
