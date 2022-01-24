#ifndef PGNES_FILE_LOGGER_H
#define PGNES_FILE_LOGGER_H

#include "abstract_logger.h"

#include <spdlog/sinks/rotating_file_sink.h>
#include <filesystem>

class FileLogger : public AbstractLogger {
public:
    explicit FileLogger(std::filesystem::path path = "", std::string name = "fileLogger") :
            AbstractLogger(std::move(name)), logFilePath(std::move(path)) {}
    void createLogger() override {
        logger = spdlog::rotating_logger_mt(loggerName, (logFilePath / loggerName).string(), 1024 * 1024, 20);
    }
protected:
    std::filesystem::path logFilePath{};
};

#endif //PGNES_FILE_LOGGER_H
