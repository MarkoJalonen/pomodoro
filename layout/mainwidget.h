#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QPushButton;
class QTextEdit;
class QGridLayout;

class MainWidget : public QWidget
{
    Q_OBJECT // Q_OBJECT macro

    public:
        explicit MainWidget(QWidget *parent = 0);
        ~MainWidget();

    private slots: // Q_SLOTS macro
        void onButtonReleased();

    private:
        QPushButton *button_;
        QGridLayout *mainLayout_;
        QTextEdit *textEditList_[10];
        int textEditCount;
};

#endif