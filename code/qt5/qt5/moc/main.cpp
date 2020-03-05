#include <QApplication>
#include <QMetaObject>
#include <QPushButton>
#include <QDebug>
#include <QMetaMethod>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QObjectを自作のものに変えればclass infoあたりの出力を得られるかも。
    QPushButton * button1 = new QPushButton();
    auto meta = button1->metaObject();

    // 参考URL
    // https://doc.qt.io/qt-5/metaobjects.html

    // meta objectから同種のclassを生成する
    auto newButton = meta->newInstance();

    // class情報の取得
    qDebug() << "QPushButtonのclass情報一覧";
    for(int i = 0; i < meta->classInfoCount(); ++i){
        qDebug() << "\t" <<meta->classInfo(i).name() << meta->classInfo(i).value();
    }

    // propertyの一覧取得
    qDebug() << "QPushButtonのproperty一覧";
    for(int i = 0; i < meta->propertyCount(); ++i){
        qDebug() << "\t" <<meta->property(i).name();
    }

    // class名の取得
    qDebug() << "class name: " << meta->className();

    // constructorのMetaMethodの取得
    qDebug() << "constructorのMetaMethodの情報一覧";
    for(int i = 0; i < meta->constructorCount(); ++i){
        qDebug() << "\t" <<meta->constructor(i).name();
    }

    // method一覧の取得
    int numMethod = meta->methodCount();
    qDebug() << "QPushButtonのmethod一覧";
    for(int i = 0; i < numMethod; ++i){
        qDebug() << "\t" <<meta->method(i).name();// << endl;
    }

    // 継承の有無の確認
    qDebug() << "QPushButtonは何かを継承している：" << meta->inherits(meta);

    // スーパークラス情報の取得
    auto super = meta->superClass();

    qDebug() << "super class name: " << super->className();

    return a.exec();
}
