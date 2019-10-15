#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}




