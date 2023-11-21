#include <QtWidgets>
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
    

    QHBoxLayout *task = new QHBoxLayout();
    QTextEdit *text = new QTextEdit();
    QPushButton *button = new QPushButton(tr("X"));
    task->addWidget(text);
    task->addWidget(button);

    taskList_[taskListCount_] = task;
    mainLayout_->addLayout(taskList_[taskListCount_],taskListCount_+1,0);
    taskListCount_++;
}

void MainWidget::removeTask()
{
    QObject *obj = sender();
    QPushButton *button = qobject_cast<QPushButton *>(obj);
    if(button != NULL)
    {
        QHBoxLayout *parent = qobject_cast<QHBoxLayout *>(obj->parent());
        QLayoutItem *child;
        while(NULL != (child = parent->takeAt(0)))
        {
            delete child;
        }
        parent->deleteLater();
    }

}