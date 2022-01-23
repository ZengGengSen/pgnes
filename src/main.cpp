#include <QApplication>
#include "driver/mainwindow.h"

#include <iostream>

using namespace pg;

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    PGMainWindow window{};
    window.init(
            argc,
            std::vector<std::string>{argv, argv + argc});
    window.show();
    return QApplication::exec();
}
