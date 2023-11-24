#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#define MAIN_MIN_W 800
#define MAX_TASK_COUNT 10

class QPushButton;
class QVBoxLayout;
class TimerWidget;

class MainWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit MainWidget(QWidget *parent = 0);
        ~MainWidget();

    private slots: // Q_SLOTS macro
        void addTask();

    private:
        QPushButton *addButton_;
        QVBoxLayout *mainLayout_;
        TimerWidget *timerWidget_;
};

#endif