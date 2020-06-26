// 参考文献
// https://doc.qt.io/qt-5/qsettings.html
// https://wiki.qt.io/How_to_Use_QSettings
// http://m-miya.blog.jp/archives/1074268062.html
// https://qiita.com/kanryu/items/b5b3064b6ce4fd94dac8
// http://qt-log.open-memo.net/sub/other__save_app_settings.html

#include <QCoreApplication>
#include <QSettings>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    // 読み込みテストするためにすこープを限定
    {
        // QSettingsの初期化
        // QCoreApplicationで設定済みの場合はいちいち設定する必要がないので次で十分
        // この場合、ユーザー固有かつNativeFormatが選択される。
        // 初期化以降はformatは変更できない模様。。。
        //QSettings settings;
        QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                           a.organizationName(), a.applicationName());

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

        // データが存在するかはcontainsで確認
        if(settings.contains("value/hoge")){
            qDebug("value/hoge exists");
        }
        else{
            qDebug("value/hoge does not exist");
        }

        // データの書き込み
        settings.setValue("value/hoge",123);
        // 同じ値を入れた場合は上書きされる
        settings.setValue("value/hoge",125);

        // syncを呼ぶまでは書き込みされないので注意。
        settings.sync();

        // データが存在するかはcontainsで確認
        if(settings.contains("value/hoge")){
            qDebug("value/hoge exists");
        }
        else{
            qDebug("value/hoge does not exist");
        }

        // ちなみにvalue/hogeは次の等価
        settings.beginGroup("value");
        settings.setValue("hoge", 1000);
        settings.endGroup();
    }

    // データの読み出し
    // 読みだすときは必ずしも情報を入れる必要はない。
    // https://doc.qt.io/qt-5/qsettings.html#fallback-mechanism
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       a.organizationName(), a.applicationName());

    int value = settings.value("value/hoge").toInt();

    qDebug("%i", value);

    return a.exec();
}
