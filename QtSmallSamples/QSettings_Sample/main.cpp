// 参考文献
// https://doc.qt.io/qt-5/qsettings.html
// https://wiki.qt.io/How_to_Use_QSettings
// http://m-miya.blog.jp/archives/1074268062.html
// https://qiita.com/kanryu/items/b5b3064b6ce4fd94dac8
// http://qt-log.open-memo.net/sub/other__save_app_settings.html
#include "mainwindow.h"

#include <QApplication>
#include <QSettings>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //　下記の項目は一意な保存場所を決定するために必要
    // 組織名の設定
    a.setOrganizationName("hogehoge");
    // ドメイン
    a.setOrganizationDomain("hoge.com");
    // アプリケーション名
    a.setApplicationName("QSettingsTest");

    // 設定ファイルの保存場所の指定
    // QSettings::setDefaultFormat(format);
    // formatには次の５つがある。
    // QSettings::NativeFormat
    //      もっとも適切な場所に保存。
    //      Windows: system registry
    //      macOS, iOS; CDPferences API
    //      Unix: textual configuration file
    // QSettings::Registry32Format
    //      Windowsのみ。32bit registry
    // QSettings::Registry64Format
    //      Windowsのみ。64bit registry
    // QSettings::IniFormat
    //      読み出し時にすべてQStrigに代わるので注意
    // QSettings::InvalidFormat
    //      ???

    // QSettingsの初期化
    QSettings settings("hoge.ini", QSettings::IniFormat);

    // 他にも初期化する方法があるが、特殊なのは
    // QSettings::Scopeで
    // QSettings::UserScope: ユーザー固有
    // QSettings::SystemScope: すべてのユーザーがアクセス可

    // QSettings(const QString &organization, const QString &application = QString(), QObject *parent = nullptr)
    // QSettings(QSettings::Scope scope, const QString &organization, const QString &application = QString(), QObject *parent = nullptr)
    // QSettings(QSettings::Format format, QSettings::Scope scope, const QString &organization, const QString &application = QString(), QObject *parent = nullptr)
    // QSettings(const QString &fileName, QSettings::Format format, QObject *parent = nullptr)

    // おまじない(#include<QTextCodec>が必要)
    settings.setIniCodec(QTextCodec::codecForName("UTF-8"));

    MainWindow w;
    w.show();
    return a.exec();
}
