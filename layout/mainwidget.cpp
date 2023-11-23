#include <QtWidgets>
#include <stdio.h>
#include "mainwidget.h"
#include "taskwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    addButton_ = new QPushButton(tr("Add Task"));
    mainLayout_ = new QGridLayout;
    mainLayout_->addWidget(addButton_,0,0);

    setLayout(mainLayout_);
    setWindowTitle(tr("Dynamic Layouts"));
    setMinimumWidth(MIN_WIDTH);

    connect 
    (
        addButton_, SIGNAL(released()), 
        this, SLOT(addTask())
    );
}

MainWidget::~MainWidget()
{
    // Memory will be freed by the OS :)
}

void MainWidget::addTask()
{
    int taskCount = children().length();
    if(taskCount <= MAX_TASK_COUNT + 1)
    {
        TaskWidget *newTask = new TaskWidget(this);
        mainLayout_->addWidget(newTask,taskCount,0);
    }
}

    