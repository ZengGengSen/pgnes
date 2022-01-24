#ifndef PGNES_MAINWINDOW_H
#define PGNES_MAINWINDOW_H

#include <QMainWindow>
#include <QRecursiveMutex>
#include <QAction>
#include <QMenuBar>

#include "core/nes.h"
#include "message_window.h"

namespace pg {
    class PGMainWindow : public QMainWindow {
    private:
        std::unique_ptr<QRecursiveMutex> mutex{};

    public:
        explicit PGMainWindow(QWidget *parent = nullptr);
        ~PGMainWindow() override = default;

        inline void lock() { mutex->lock(); }
        inline void unlock() { mutex->unlock(); }
        bool tryLock(int timeout) { return mutex->tryLock(timeout); }

        void init(const std::vector<std::string> &argv);

    private:
        void showUsage();
        void createMainMenu();

        Nes nes{};

        std::unique_ptr<MessageWindow> messageWindow{};
        std::unique_ptr<QAction> msgLogAct{};
        std::unique_ptr<QMenuBar> menubar{};
        std::shared_ptr<Logger> logger;
    };

    extern std::unique_ptr<PGMainWindow> mainWindow;
}


#endif //PGNES_MAINWINDOW_H
