#ifndef PGNES_LOGGER_H
#define PGNES_LOGGER_H

#include <QObject>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/ostream_sink.h>
#include <sstream>
#include <filesystem>

namespace pg {

    class Logger : public QObject {
    Q_OBJECT
    public:
        explicit Logger(const std::filesystem::path &filePath = "", const std::string &loggerName = "MultiLogger") {
            std::vector<spdlog::sink_ptr> sinks;

            sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_mt>());
            sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                    (filePath / loggerName).string(), 1024 * 1024, 5));
            sinks.push_back(std::make_shared<spdlog::sinks::ostream_sink_mt>(oStringStream));

            logger = std::make_shared<spdlog::logger>("MessageLog", sinks.begin(), sinks.end());
            logger = std::make_shared<spdlog::logger>(loggerName, sinks.begin(), sinks.end());
        }

        template<class... Args>
        void trace(fmt::format_string<Args...> fmt, Args &&...args) {
            logger->trace(fmt, args...); emit loggerChange();
        }
        template<typename T>
        void trace(const T &msg) { logger->trace(msg); emit loggerChange(); }

        template<class... Args>
        void debug(fmt::format_string<Args...> fmt, Args &&...args) {
            logger->debug(fmt, args...); emit loggerChange();
        }
        template<typename T>
        void debug(const T &msg) { logger->debug(msg); emit loggerChange(); }

        template<class... Args>
        void info(fmt::format_string<Args...> fmt, Args &&...args) { logger->info(fmt, args...);emit loggerChange(); }
        template<typename T>
        void info(const T &msg) { logger->info(msg); emit loggerChange(); }

        template<class... Args>
        void warn(fmt::format_string<Args...> fmt, Args &&...args) { logger->warn(fmt, args...); emit loggerChange(); }
        template<typename T>
        void warn(const T &msg) { logger->warn(msg); emit loggerChange(); }

        template<class... Args>
        void error(fmt::format_string<Args...> fmt, Args &&...args) {
            logger->error(fmt, args...); emit loggerChange();
        }
        template<typename T>
        void error(const T &msg) { logger->error(msg); emit loggerChange(); }

        template<class... Args>
        void critical(fmt::format_string<Args...> fmt, Args &&...args) {
            logger->critical(fmt, args...); emit loggerChange();
        }
        template<typename T>
        void critical(const T &msg) { logger->critical(msg); emit loggerChange(); }

        void clear() {
            oStringStream.str("");
            emit loggerChange();
        }

        std::string getStr() {
            return oStringStream.str();
        }

    protected:
        std::ostringstream oStringStream;
        std::shared_ptr<spdlog::logger> logger;

    signals:
        void loggerChange();
    };

}

#endif //PGNES_LOGGER_H
