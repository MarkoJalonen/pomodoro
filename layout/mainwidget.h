#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#define MIN_WIDTH 400

class QPushButton;
class QTextEdit;
class QGridLayout;
class QHBoxLayout;

class MainWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit MainWidget(QWidget *parent = 0);
        ~MainWidget();

    private slots: // Q_SLOTS macro
        void addTask();
        void removeTask();

    private:
        QPushButton *button_;
        QGridLayout *mainLayout_;
        QHBoxLayout *taskList_[10];
        int taskListCount_;
};

#endif