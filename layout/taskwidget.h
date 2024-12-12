// Copyright 2024 Marko Jalonen

#ifndef LAYOUT_TASKWIDGET_H_
#define LAYOUT_TASKWIDGET_H_

#include <QWidget>

#define MAX_TASK_H 50

class QHBoxLayout;
class QPushButton;
class QTextEdit;

class TaskWidget : public QWidget {
Q_OBJECT  // Q_OBJECT macro

 public:
    explicit TaskWidget(QWidget *parent = 0);
    ~TaskWidget();

 private slots:  // Q_SLOTS macro
    void deleteTask();

 private:
    QHBoxLayout *taskLayout_;
    QTextEdit *textBox_;
    QPushButton *deleteButton_;
    QWidget *parent_;
};

#endif  // LAYOUT_TASKWIDGET_H_
