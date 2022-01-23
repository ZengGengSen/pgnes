enable_testing()

find_package(GTest REQUIRED)

include_directories(
        ${GTEST_INCLUDE_DIRS}
)

set(
        Test
        ${Core}
        config_test.cpp
)

add_executable(ConfigTest ${Test})
target_link_libraries(ConfigTest GTest::gtest GTest::gtest_main)

add_test(AllTestsInFoo ConfigTest)