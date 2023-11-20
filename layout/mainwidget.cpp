#include <QtWidgets>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    button_ = new QPushButton(tr("Add widget"));

    mainLayout_ = new QGridLayout;
    mainLayout_->addWidget(button_,0,0);
    setLayout(mainLayout_);
    setWindowTitle(tr("Dynamic Layouts"));

    textEditCount = 0;

    // Connect signals to member function pointers
    connect 
    (
        button_, SIGNAL(released()), 
        this, SLOT(onButtonReleased())
    );
}

MainWidget::~MainWidget()
{
    delete button_;
    // delete all textEdits
}

void MainWidget::onButtonReleased()
{
    if(textEditCount >= 9) return;
    textEditList_[textEditCount] = new QTextEdit();
    mainLayout_->addWidget(textEditList_[textEditCount],textEditCount+1,0);
    textEditCount++;
}