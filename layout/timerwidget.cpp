#include <QtWidgets>
#include "timerwidget.h"

TimerWidget::TimerWidget(QWidget *parent) : QWidget(parent)
{
    timerLayout_ = new QHBoxLayout();
    controlsLayout_ = new QVBoxLayout();
    pausePlayButton_ = new QPushButton(tr("⏯"));
    skipButton_ = new QPushButton(tr("⏭"));
    timerReadout_ = new QLCDNumber();
    timerStatus_ = new QLabel(tr("Relax"));
    timer_ = new QTimer;
    time_ = new QTime;

    timerStatus_->setAlignment(Qt::AlignCenter);
    controlsLayout_->addWidget(timerStatus_);
    controlsLayout_->addWidget(pausePlayButton_);
    controlsLayout_->addWidget(skipButton_);
    timerLayout_->addWidget(timerReadout_);
    timerLayout_->addLayout(controlsLayout_);

    setLayout(timerLayout_);
    setFixedSize(300, 100);

    connect 
    (
        timer_, SIGNAL(timeout()), 
        this, SLOT(updateTime())
    );
    connect
    (
        pausePlayButton_, SIGNAL(released()),
        this, SLOT(toggleTimer())
    );
    connect
    (
        skipButton_, SIGNAL(released()),
        this, SLOT(skip())
    );

    timerReadout_->setSegmentStyle(QLCDNumber::Filled);
    time_->setHMS(0,25,0);
    timerReadout_->display("25:00");

    currState_ = Timeout;
    prevState_ = Relax;
}   

TimerWidget::~TimerWidget()
{
    delete timerLayout_;
    delete controlsLayout_;
    delete pausePlayButton_;
    delete skipButton_;
    delete timerReadout_;
    delete timerStatus_;
    delete timer_;
    delete time_;
}

void TimerWidget::updateTime()
{
    if (currState_ == Focus || currState_ == Relax)
    {
        if (time_->toString() == "00:00:00")
        {
            timer_->stop();
            prevState_ = currState_;
            currState_ = Timeout;
            updateTime();
        }
        else
        {
            *time_ = time_->addSecs(-1);
            QString text = time_->toString("mm:ss");
            timerReadout_->display(text);
        }
    } 
    else if (currState_ == Timeout)
    {
        if(prevState_ == Focus)
        {
            time_->setHMS(0,5,0);
            timerReadout_->display("05:00");
            timerStatus_->setText(tr("Timeout"));
        }
        else if (prevState_ == Relax)
        {
            time_->setHMS(0,25,0);
            timerReadout_->display("25:00");
            timerStatus_->setText(tr("Timeout"));
        }
    }
}

void TimerWidget::toggleTimer()
{
    switch (currState_)
    {
        case Timeout:
        {
            enum State temp = currState_;
            if(prevState_ == Focus){
                currState_ = Relax;
                timerStatus_->setText("Relax");
            }
            else 
            {
                currState_ = Focus;
                timerStatus_->setText("Focus!");
            }
            prevState_ = temp;
            timer_->start(1000);
            break;
        }
        case Paused:
        {
            currState_ = prevState_;
            timer_->start(1000);
            break;
        }
        default:
        {   prevState_ = currState_;
            currState_ = Paused;
            timerStatus_->setText(tr("Paused"));
            break;
        }
    } 

}

void TimerWidget::skip()
{
    prevState_ = currState_ == Paused ? prevState_ : currState_;
    currState_ = Timeout;
    updateTime();
}