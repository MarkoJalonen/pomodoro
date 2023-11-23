#include <QtWidgets>
#include <stdio.h>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    button_ = new QPushButton(tr("Add Task"));

    mainLayout_ = new QGridLayout;
    mainLayout_->addWidget(button_,0,0);
    setLayout(mainLayout_);
    setWindowTitle(tr("Dynamic Layouts"));

    setMinimumWidth(MIN_WIDTH);

    taskListCount_ = 0;

    // Connect signals to member function pointers
    connect 
    (
        button_, SIGNAL(released()), 
        this, SLOT(addTask())
    );
}

MainWidget::~MainWidget()
{
    // Memory will be freed by the OS :)
}

void MainWidget::addTask()
{
    if(taskListCount_ >= 9) return;

    QHBoxLayout *taskLayout = new QHBoxLayout();
    QWidget *taskWidget = new QWidget();
    QTextEdit *text = new QTextEdit();
    QPushButton *button = new QPushButton(tr("❌"));

    connect 
    (
        button, SIGNAL(released()), 
        this, SLOT(removeTask())
    );

    taskLayout->addWidget(text);
    taskLayout->addWidget(button);
    taskWidget->setLayout(taskLayout);
    taskWidget->setMaximumHeight(50);
    
    mainLayout_->addWidget(taskWidget,taskListCount_+1,0);
    taskListCount_++;
}

void MainWidget::removeTask()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QWidget *parent = qobject_cast<QWidget *>(button->parent());
    if(button && parent)
    {
        parent->deleteLater();
        taskListCount_--;   
    }           
}