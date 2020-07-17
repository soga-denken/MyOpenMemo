// 参考
// https://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html
// https://doc.qt.io/qt-5/qtwidgets-mainwindows-menus-example.html
// https://doc.qt.io/qt-5/qmenubar.html
// http://qt-log.open-memo.net/sub/menubar__make_menubar.html
// https://code-note-jp.blogspot.com/2019/05/qt-qmenubarqmenu.html

#include "mainwindow.h"

#include <QApplication>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
