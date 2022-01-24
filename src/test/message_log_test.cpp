#include "utils/logger/logger_facatory.h"
#include <gtest/gtest.h>

class LoggerTest : public testing::Test {
public:
    static void SetUpTestCase() {
        std::cout << "LoggerTest run before first case..." << std::endl;
    }

    static void TearDownTestCase() {
        std::cout << "LoggerTest run after last case..." << std::endl;
    }

    void SetUp() override {
        std::cout << "LoggerTest before test case..." << std::endl;
    }

    void TearDown() override {
        std::cout << "LoggerTest after test case..." << std::endl;
    }

    void printInfo() {
        logger->createLogger();
        logger->info("Hello, {}!", "World");
        logger->info("Welcome to spdlog!");
        logger->error("Some error message with arg: {}", 1);

        logger->warn("Easy padding in numbers like {:08d}", 12);
        logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
        logger->info("Support for floats {:03.2f}", 1.23456);
        logger->info("Positional args are {1} {0}..", "too", "supported");
        logger->info("{:<30}", "left aligned");
        logger->deleteLogger();
    }

protected:
    std::shared_ptr<AbstractLogger> logger{};
};

TEST_F(LoggerTest, StdOutLoggerTest) {
    logger = std::move(std::make_shared<StdOutLogger>());
    printInfo();
}
TEST_F(LoggerTest, StdErrLoggerTest) {
    logger = std::make_shared<StdErrLogger>();
    printInfo();
}
TEST_F(LoggerTest, FileLoggerTest) {
    logger = std::make_shared<FileLogger>();
    printInfo();
}
TEST_F(LoggerTest, OStringStreamLoggerTest) {
    std::ostringstream oss;
    logger = std::make_shared<OStringStreamLogger>(oss);
    printInfo();
    std::cout << oss.str();
}
TEST_F(LoggerTest, MultiLoggerTest) {
    std::ostringstream oss;
    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_mt>());
    sinks.push_back(std::make_shared<spdlog::sinks::stderr_sink_mt>());
    sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("fileLogger", 1024 * 1024, 10));
    sinks.push_back(std::make_shared<spdlog::sinks::ostream_sink_mt>(oss));
    logger = std::make_shared<MultiLogger>(sinks);
    printInfo();
    std::cout << oss.str();
}

TEST(OSS_TEST, OT) {
    std::ostringstream oStringStream;
    oStringStream << "HelloWorld!\n";
    std::cout << oStringStream.str();
    oStringStream.str("");
    std::cout << oStringStream.str();
}