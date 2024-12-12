// Copyright 2024 Marko Jalonen

#include <QtWidgets>
#include "mainwidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWidget w;
    w.show();

    return a.exec();
}
