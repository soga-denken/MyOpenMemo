#include "myDialog.h"

//　自動で生成されるヘッダーを追加すること
#include "ui_dialog.h"

//MyDialog::MyDialog()
MyDialog::MyDialog(QWidget * parent) :
    QDialog(parent)
  , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // uiのsignalsとslotsはformの下のシグナルとスロットから確認できる。
    connect(ui->buttonBox, &QDialogButtonBox::accepted,
            this, &MyDialog::onClicked);

    connect(this, &MyDialog::testSignal,
            this, &MyDialog::onTest);
}

void MyDialog::onClicked(){
    qDebug("on clicked");
}

void MyDialog::onTest(){
    qDebug("on test");
}
