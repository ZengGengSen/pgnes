#include "message_window.h"

namespace pg {
    MessageWindow::MessageWindow(QWidget *parent) :
            QDialog(parent),
            mainLayout(std::make_unique<QVBoxLayout>()),
            txtView(std::make_unique<QPlainTextEdit>()),
            hBox(std::make_unique<QHBoxLayout>()),
            clearBtn(std::make_unique<QPushButton>(tr("Clear"))),
            closeBtn(std::make_unique<QPushButton>(tr("Close"))),
            updateTimer(std::make_unique<QTimer>(this)),
            logger(std::make_shared<Logger>()) {
        setWindowTitle(tr("Message Log Viewer"));
        resize(512, 512);

        txtView->setReadOnly(true);
        hBox->addWidget(clearBtn.get(), 1);
        hBox->addStretch(5);
        hBox->addWidget(closeBtn.get(), 1);
        mainLayout->addWidget(txtView.get());
        mainLayout->addLayout(hBox.get());
        setLayout(mainLayout.get());

        connect(clearBtn.get(), SIGNAL(clicked(void)), this, SLOT(clearLog()));
        connect(closeBtn.get(), SIGNAL(clicked(void)), this, SLOT(close()));

        connect(logger.get(), &Logger::loggerChange, this, &MessageWindow::updatePeriodic);

        updateTimer->start(500);

        txtView->setPlainText(logger->getStr().c_str());
        txtView->moveCursor(QTextCursor::End);
    }

    MessageWindow::~MessageWindow() = default;

    void MessageWindow::updatePeriodic() {
        txtView->setPlainText(logger->getStr().c_str());
        txtView->moveCursor(QTextCursor::End);
    }

    void MessageWindow::clearLog() {
        logger->clear();
    }

}

