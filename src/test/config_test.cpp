#include <gtest/gtest.h>
#include "core/config.h"

TEST(CONFIG_TEST, LOAD_TEST) {
    std::unique_ptr<Config> config = std::make_unique<Config>();
    config->load();
    EXPECT_FALSE(config->getBool("useSDL"));
    config->save();
}

