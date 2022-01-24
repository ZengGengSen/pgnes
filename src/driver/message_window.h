#ifndef PGNES_MESSAGE_WINDOW_H
#define PGNES_MESSAGE_WINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QSettings>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QTimer>
#include <utility>

#include "logger.h"

namespace pg {
    class MessageWindow : public QDialog {
    Q_OBJECT
    public:
        explicit MessageWindow(QWidget *parent = nullptr);
        ~MessageWindow() override;

        void setLogger(std::shared_ptr<Logger> log) {
            logger = std::move(log);
            connect(logger.get(), &Logger::loggerChange, this, &MessageWindow::updatePeriodic);
        }

    private:
        std::unique_ptr<QVBoxLayout> mainLayout;
        std::unique_ptr<QHBoxLayout> hBox;
        std::unique_ptr<QPushButton> clearBtn, closeBtn;
        std::unique_ptr<QPlainTextEdit> txtView;
        std::unique_ptr<QTimer> updateTimer;
        std::shared_ptr<Logger> logger;

    private slots:
        void updatePeriodic();
        void clearLog();
    };
}

#endif //PGNES_MESSAGE_WINDOW_H
