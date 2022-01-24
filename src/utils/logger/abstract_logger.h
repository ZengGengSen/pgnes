#ifndef PGNES_ABSTRACT_LOGGER_H
#define PGNES_ABSTRACT_LOGGER_H

#include <spdlog/spdlog.h>
#include <utility>

class AbstractLogger {
public:
    explicit AbstractLogger(std::string name) : loggerName(std::move(name)) {}
    virtual ~AbstractLogger() = default;

    virtual void createLogger() = 0;
    std::shared_ptr<spdlog::logger> getLogger() { return logger; };
    void deleteLogger() { spdlog::drop(loggerName); }

    void setLevel(spdlog::level::level_enum level) { logger->set_level(level); }

    template<class... Args>
    void trace(fmt::format_string<Args...> fmt, Args &&...args) { logger->trace(fmt, args...); }
    template<typename T>
    void trace(const T &msg) { logger->trace(msg); }

    template<class... Args>
    void debug(fmt::format_string<Args...> fmt, Args &&...args) { logger->debug(fmt, args...); }
    template<typename T>
    void debug(const T &msg) { logger->debug(msg); }

    template<class... Args>
    void info(fmt::format_string<Args...> fmt, Args &&...args) { logger->info(fmt, args...); }
    template<typename T>
    void info(const T &msg) { logger->info(msg); }

    template<class... Args>
    void warn(fmt::format_string<Args...> fmt, Args &&...args) { logger->warn(fmt, args...); }
    template<typename T>
    void warn(const T &msg) { logger->warn(msg); }

    template<class... Args>
    void error(fmt::format_string<Args...> fmt, Args &&...args) { logger->error(fmt, args...); }
    template<typename T>
    void error(const T &msg) { logger->error(msg); }

    template<class... Args>
    void critical(fmt::format_string<Args...> fmt, Args &&...args) { logger->critical(fmt, args...); }
    template<typename T>
    void critical(const T &msg) { logger->critical(msg); }

protected:
    std::string loggerName{};
    std::shared_ptr<spdlog::logger> logger{};
};

#endif //PGNES_ABSTRACT_LOGGER_H
