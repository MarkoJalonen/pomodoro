#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>

#define MAX_TASK_H 50

class QHBoxLayout;
class QPushButton;
class QTextEdit;

class TaskWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit TaskWidget(QWidget *parent = 0);
        ~TaskWidget();

    private slots: // Q_SLOTS macro
        void deleteTask();

    private:
        QHBoxLayout *taskLayout_;
        QTextEdit *textBox_;
        QPushButton *deleteButton_;    
        QWidget *parent_;
};

#endif