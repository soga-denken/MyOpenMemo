#ifndef MYDIALOG_H
#define MYDIALOG_H

#include "myDialog_global.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
// class名はformを追加したときの名前
namespace Ui { class Dialog; }
QT_END_NAMESPACE

// 継承すべきクラスは
// Dialog: QDialog
// MainWindow: QMainWindow
// Widget: QWidget
class MYDIALOG_EXPORT MyDialog: public QDialog
{
    // いつものおまじない
    Q_OBJECT

public:
//    MyDialog();
    // widgetにするので親を追加する。
    MyDialog(QWidget *parent = nullptr);
signals:
    void testSignal();

public slots:
    void onClicked();
    void onTest();

public slots:
    // QDialogButtonBoxのslotsをoverrideする。
    // base classのslotsはすでにconnectされており、新たにconnectする必要がない。
    void accept() override{
        qDebug("qDialogButtonBox::accpet is overriden");

        // overrideした場合は明示的にベースクラスを実行する。
        // これをしないとボタンを押しても動かない（笑
        QDialog::accept();

    };

    void reject() override{
        qDebug("qDialogButtonBox::reject is overriden");

        // overrideした場合は明示的にベースクラスを実行する。
        // これをしないとボタンを押しても動かない（笑
        QDialog::reject();
    };

// uiのメンバーを追加する
private:
    Ui::Dialog *ui;
};

#endif // MYDIALOG_H
