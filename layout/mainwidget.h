#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#define MIN_WIDTH 400
#define MAX_TASK_COUNT 10

class QPushButton;
class QGridLayout;

class MainWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit MainWidget(QWidget *parent = 0);
        ~MainWidget();

    private slots: // Q_SLOTS macro
        void addTask();

    private:
        QPushButton *addButton_;
        QGridLayout *mainLayout_;
};

#endif