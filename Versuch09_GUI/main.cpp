#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapIoNrw* maploader = new MapIoNrw();
    MainWindow w(nullptr, maploader);
    w.show();
    return a.exec();
}
