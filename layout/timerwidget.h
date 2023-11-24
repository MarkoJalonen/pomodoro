#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>

#define TIMER_MIN_W 200

class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QLCDNumber;
class QLabel;
class QTimer;
class QTime;

class TimerWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit TimerWidget(QWidget *parent = 0);
        ~TimerWidget();

    private slots: // Q_SLOTS macro
        void updateTime();
        void toggleTimer();
        void skip();

    private:
        QHBoxLayout *timerLayout_;
        QVBoxLayout *controlsLayout_;
        QPushButton *pausePlayButton_, *skipButton_;
        QLCDNumber *timerReadout_;
        QLabel *timerStatus_;
        QTimer *timer_;
        QTime *time_;
        enum State {Paused, Focus, Relax, Timeout};
        enum State currState_, prevState_;
};

#endif