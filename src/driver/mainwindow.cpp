#include <QApplication>
#include "mainwindow.h"

namespace pg {
    std::unique_ptr<PGMainWindow> mainWindow{};

    PGMainWindow::PGMainWindow(QWidget *parent) :
            QMainWindow(parent),
            logger(std::make_shared<Logger>()),
            messageWindow(std::make_unique<MessageWindow>(this)) {
        createMainMenu();
        messageWindow->setLogger(logger);
    }

    void PGMainWindow::init(const std::vector<std::string> &argv) {
        if (argv.cend() !=
            std::find_if(argv.cbegin(), argv.cend(),
                         [](const std::string &arg) { return arg == "--help" || arg == "-h"; })) {
            showUsage();
            QApplication::exit(0);
        }

        logger->info("Starting pgnes 1.0.0 ...\n");

    }

    // TODO: this is show the application Usage Manual
    void PGMainWindow::showUsage() {

    }

    void PGMainWindow::createMainMenu() {
        menubar = std::make_unique<QMenuBar>(this);
        this->setMenuBar(menubar.get());

        msgLogAct = std::make_unique<QAction>(tr("&Message Log"), this);
        msgLogAct->setStatusTip(tr("Message Log"));
        // msgLogAct->setIcon( style()->standardIcon( QStyle::SP_MessageBoxWarning ) );
        connect(msgLogAct.get(), SIGNAL(triggered()), messageWindow.get(), SLOT(show()));
        menubar->addAction(msgLogAct.get());

    }
}
