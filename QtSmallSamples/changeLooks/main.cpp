#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QDebug>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString currentStyle = a.style()->metaObject()->className();

    qDebug() << currentStyle << Qt::endl;

    MainWindow w(&a);

    w.show();

    return a.exec();
}
