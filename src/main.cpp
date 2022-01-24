#include <QApplication>
#include "driver/mainwindow.h"

#include <iostream>

using namespace pg;

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};

    mainWindow = std::make_unique<PGMainWindow>();

    mainWindow->init(std::vector<std::string>{argv, argv + argc});
    mainWindow->show();

    return QApplication::exec();
}
