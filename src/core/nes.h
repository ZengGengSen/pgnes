#ifndef PGNES_NES_H
#define PGNES_NES_H

#include "config.h"

class Nes {
public:

    std::shared_ptr<Config> getConfig() const { return config; }

private:
    std::shared_ptr<Config> config;
};


#endif //PGNES_NES_H
