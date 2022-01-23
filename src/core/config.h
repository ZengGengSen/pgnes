#ifndef PGNES_CONFIG_H
#define PGNES_CONFIG_H

#include "document.h"
#include <string>

class Config {
public:
    Config() = default;

    ~Config() = default;

    void load(std::string configFilePath = "");

    void save(std::string configFilePath = "");

    void init() {
        // TODO:设置音频配置

        // TODO:设置颜色配置

        // TODO:设置……
    }

    bool getBool(const char *key) const {
        return jsonDocument[key].GetBool();
    }

    int getInt(const char *key) const {
        return jsonDocument[key].GetInt();
    }

    int64_t getInt64(const char *key) const {
        return jsonDocument[key].GetInt64();
    }

    double getDouble(const char *key) const {
        return jsonDocument[key].GetDouble();
    }

    std::string getString(const char *key) const {
        return jsonDocument[key].GetString();
    }

private:
    rapidjson::Document jsonDocument;
};

#endif //PGNES_CONFIG_H
