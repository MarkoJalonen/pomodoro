#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>

#define TIMER_MIN_W 200

class QVBoxLayout;
class QPushButton;
class QLCDNumber;
class QLabel;
class QTimer;

class TimerWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit TimerWidget(QWidget *parent = 0);
        ~TimerWidget();

    private slots: // Q_SLOTS macro
        void updateTime();

    private:
        QVBoxLayout *timerLayout_;
        QPushButton *pausePlayButton_;
        QPushButton *skipButton_;
        QLCDNumber *timerReadout_;
        QLabel *timerStatus_;
        QTimer *timer_;
};

#endif