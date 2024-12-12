// Copyright 2024 Marko Jalonen

#include <QtWidgets>
#include "mainwidget.h"
#include "taskwidget.h"
#include "timerwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    addButton_ = new QPushButton(tr("Add Task"));
    mainLayout_ = new QVBoxLayout();
    timerWidget_ = new TimerWidget();
    mainLayout_->addWidget(timerWidget_);
    mainLayout_->addWidget(addButton_);

    setLayout(mainLayout_);
    setWindowTitle(tr("Pomodoro"));

    connect(
        addButton_, SIGNAL(released()),
        this, SLOT(addTask()));
}

MainWidget::~MainWidget() {
    // Memory will be freed by the OS :)
}

void MainWidget::addTask() {
    int taskCount = children().length();
    if (taskCount <= MAX_TASK_COUNT + 1) {
        TaskWidget *newTask = new TaskWidget(this);
        mainLayout_->addWidget(newTask);
    }
}
