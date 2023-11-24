#include <QtWidgets>
#include "timerwidget.h"

TimerWidget::TimerWidget(QWidget *parent) : QWidget(parent)
{
    timerLayout_ = new QVBoxLayout();
    pausePlayButton_ = new QPushButton();
    skipButton_ = new QPushButton();
    timerReadout_ = new QLCDNumber();
    timerStatus_ = new QLabel();
    timer_ = new QTimer;

    timerLayout_->addWidget(timerReadout_);
    setLayout(timerLayout_);
    setMinimumWidth(TIMER_MIN_W);

    connect 
    (
        timer_, SIGNAL(timeout()), 
        this, SLOT(updateTime())
    );
    timer_->start(1000);

    updateTime();
}   

TimerWidget::~TimerWidget()
{

}

void TimerWidget::updateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    timerReadout_->display(text);
}