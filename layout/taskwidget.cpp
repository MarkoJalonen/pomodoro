#include <QtWidgets>
#include "taskwidget.h"

TaskWidget::TaskWidget(QWidget *parent) : QWidget(parent)
{
    parent_ = parent;
    taskLayout_ = new QHBoxLayout();
    textBox_ = new QTextEdit();
    deleteButton_ = new QPushButton(tr("❌"));

    taskLayout_->addWidget(textBox_);
    taskLayout_->addWidget(deleteButton_);
    setLayout(taskLayout_);
    setMaximumHeight(MAX_TASK_H);

    connect 
    (
        deleteButton_, SIGNAL(released()), 
        this, SLOT(deleteTask())
    );
}

TaskWidget::~TaskWidget()
{
    delete textBox_;
    delete deleteButton_;
    delete taskLayout_;
}

void TaskWidget::deleteTask() 
{
    deleteLater();
    parent_->adjustSize();
}
