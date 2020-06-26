#include "mainwindow.h"

#include <QApplication>

// reference
// https://qiita.com/argama147/items/30da69e4c1088917d522

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
