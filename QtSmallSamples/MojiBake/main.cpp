// 日本語を入力する場合はBOMを付ける。
// 右クリックしてBOMを保存を選択する。
// ただし、gitとかをつかう場合は素直に英語で作って、翻訳した方がよい。

#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPushButton * button = new QPushButton();
    // 面倒だが、QString::fromLocal8Bit()で囲う必要あり。
    button->setText(QString::fromLocal8Bit("入力ファイルを指定"));
    w.setCentralWidget(button);

    w.show();
    return a.exec();
}
