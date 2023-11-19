#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QProcess> // QProcess on stack, not pointer

class QPushButton;
class QTextBrowser;

class MainWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit MainWidget(QWidget *parent = 0);
        ~MainWidget();

    private slots: // Q_SLOTS macro
        void onButtonReleased();
        void onCaptureProcessOutput();

    private:
        QPushButton* button_;
        QTextBrowser* textBrowser_;
        QProcess process_; // Terminal
};

#endif