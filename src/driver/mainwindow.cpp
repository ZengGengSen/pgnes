#include <QApplication>
#include "mainwindow.h"

namespace pg {
    PGMainWindow::PGMainWindow(QWidget *parent) : QMainWindow(parent) {

    }

    void PGMainWindow::init(int argc, const std::vector<std::string> &argv) {
        if (argv.cend() !=
            std::find_if(argv.cbegin(), argv.cend(),
                         [](const std::string &arg) { return arg == "--help" || arg == "-h"; })) {
            showUsage();
            QApplication::exit(0);
        }


    }

    // TODO: this is show the application Usage Manual
    void PGMainWindow::showUsage() {

    }

}
