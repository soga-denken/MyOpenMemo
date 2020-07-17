// 参考情報
// https://code-note-jp.blogspot.com/2019/04/qt-hello-world.html

// GUIを使う場合はQCoreApplicationではなく、QApplicationを使う。
//#include <QCoreApplication>

// QApplicationをつかうにはproファイルでwidgetを追加する必要がある
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // memo
    // trはQObjectのstatic関数なのでスコープ外で使う場合はQObject::trとする。
    QLabel label(QObject::tr("Hello World!"), nullptr);

    label.show();

    return a.exec();
}
