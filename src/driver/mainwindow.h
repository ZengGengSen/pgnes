#ifndef PGNES_MAINWINDOW_H
#define PGNES_MAINWINDOW_H

#include <QMainWindow>
#include <QRecursiveMutex>

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

        void init(int argc, const std::vector<std::string> &argv);

    private:
        void showUsage();

    };
}


#endif //PGNES_MAINWINDOW_H
