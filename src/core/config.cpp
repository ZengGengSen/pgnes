#include <fstream>
#include "istreamwrapper.h"
#include "ostreamwrapper.h"
#include "writer.h"
#include <iostream>

#include "config.h"

const char *defaultFilePath = "pgfc.json";

const char *defaultConfig{
        R"jsonConfig(
        {
            "useSDL": true,
            "SDL": {
                "useSound": true,
                "Sound": {
                    "Volume": 255,
                    "TriangleVolume": 255,
                    "Square1Volume": 255,
                    "Square2Volume": 255,
                    "NoiseVolume": 255,
                    "PCMVolume": 255,
                    "Rate": 44100,
                    "Quality": 1,
                    "RecordFile": "",
                    "BufSize": 128,
                    "LowPass": 0,
                    "UseGlobalFocus": 1
                }
            }
        })jsonConfig"
};

void Config::load(std::string configFilePath) {
    if (configFilePath.empty()) {
        configFilePath = defaultFilePath;
    }

    std::ifstream configFile(configFilePath);
    if (configFile.is_open()) {
        rapidjson::IStreamWrapper isw(configFile);
        jsonDocument.ParseStream(isw);
        configFile.close();
    } else {
        jsonDocument.Parse(defaultConfig);
        save(configFilePath);
    }
}

void Config::save(std::string configFilePath) {
    if (configFilePath.empty()) {
        configFilePath = defaultFilePath;
    }

    std::ofstream configFile(configFilePath);
    rapidjson::OStreamWrapper osw(configFile);
    rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
    jsonDocument.Accept(writer);
    configFile.close();
}

