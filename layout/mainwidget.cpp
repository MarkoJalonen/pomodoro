#include <QtWidgets>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    button_ = new QPushButton(tr("Push Me!"));
    textBrowser_ = new QTextBrowser();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(button_,0,0);
    mainLayout->addWidget(textBrowser_,1,0);
    setLayout(mainLayout);
    setWindowTitle(tr("Buttons connected to processes"));

    // Connect signals to member function pointers
    connect 
    (
        button_, SIGNAL(released()), 
        this, SLOT(onButtonReleased())
    );
    connect
    (
        &process_, SIGNAL(readyReadStandardOutput()),
        this, SLOT(onCaptureProcessOutput()) 
    );
}

MainWidget::~MainWidget()
{
    delete button_;
    delete textBrowser_;
}

void MainWidget::onButtonReleased()
{
    textBrowser_->clear();
    textBrowser_->append(tr("Running command:"));

    // Set process output stream and command
    process_.setCurrentWriteChannel(QProcess::StandardOutput);
    process_.setProgram("ls");
    process_.setArguments({"-alh", "/home/marko/Documents/studies"});
    process_.start();
}

void MainWidget::onCaptureProcessOutput()
{
    // Check that the signal sender object was a process pointer
    // AKA if the cast returns a NULL or not
    QProcess* process = qobject_cast<QProcess*>(sender());
    if(process) textBrowser_->append(process->readAllStandardOutput());
}