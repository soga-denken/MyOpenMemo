#include <QApplication>
#include <QMetaObject>
#include <QDebug>
#include <QMetaMethod>

#include <iostream>

// reference
// https://stackoverflow.com/questions/36521599/qt-is-there-a-way-to-get-a-list-of-all-custom-slots-and-signals-in-a-class

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // メタオブジェクトの取得
    const QMetaObject * meta = a.metaObject();

    QList<QString> slotSignatures;
    QList<QString> signalSignatures;

    // Push Buttonのslotsおよびsignalsを取得する
    for(int methodIdx = meta->methodOffset(); methodIdx < meta->methodCount(); ++methodIdx)
    {
      QMetaMethod mmTest = meta->method(methodIdx);
      switch((int)mmTest.methodType()) {
        case QMetaMethod::Signal:
          signalSignatures.append(QString(mmTest.methodSignature()));
          break;
        case QMetaMethod::Slot:
          slotSignatures.append(QString(mmTest.methodSignature()));
          break;
      }
    }

    std::cout << "Slots:" << std::endl;
    foreach(QString signature, slotSignatures)
        std::cout << "\t" << signature.toStdString() << std::endl;

    std::cout << "Signals:" << std::endl;
    foreach(QString signature, signalSignatures)
        std::cout << "\t" << signature.toStdString() << std::endl;

    return 0;
}
