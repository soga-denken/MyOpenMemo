#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Qt4 type connect
    connect(ui->Button0, SIGNAL(clicked()), this, SLOT(button0()));
    connect(ui->Button1, SIGNAL(clicked()), this, SLOT(button1()));

    // Qt5 type
    connect(ui->Button2, &QPushButton::clicked, this, &MainWindow::button2);

    // Qt5 Functor
    connect(ui->Button3, &QPushButton::clicked, this, &MainWindow::button3);

    connect(ui->Button4, &QPushButton::clicked, this, &MainWindow::button4);

    connect(ui->Button5, &QPushButton::clicked, this, &MainWindow::button5);

    connect(ui->Button6, &QPushButton::clicked, this, &MainWindow::button6);

    connect(ui->Button7, &QPushButton::clicked, this, &MainWindow::button7);
    // lambdaを使う場合。
    //connect(ui->Button4, &QPushButton::clicked, [=](){qDebug("This is for a debug");});

    // 同名のslotsがある場合への対処1
    // static_cast
    //connect(ui->Button3,&QPushButton::clicked,
    //        this,static_cast<void (MainWindow::*)()>(&MainWindow::button3));

    // 同名のslotsがある場合への対処2
    // 関数ポインタを使う
    //void (MainWindow::*newButton4)(int) = &MainWindow::button4;
    //connect(ui->Button4,&QPushButton::clicked,
    //        this,&newButton4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button0(){
    qDebug("getOpenFileName");

    // OpenFileDialogの使い方

    // 1.filterの指定
    // 書式は次のとおり
    // 見出し(拡張子1 拡張子1)
    QString Filter1 = tr("all(*.*);;text(*.txt);;script(*.sh)");
    QString selFilter = tr("text(*.txt)");
    QString title = tr("Open a File");


    // こんな使う方あるの知らんかった。。。
    QFileDialog dialog;
    dialog.setViewMode(QFileDialog::Detail);

    QString fileName = dialog.getOpenFileName(
                // 親
                this,
                // タイトル
                title,
                // デフォルトパス
                "C:/",
                // 表示する拡張子の指定
                Filter1,
                // dialog表示に選択しているフィルター
                &selFilter
                // オプション
                // https://doc.qt.io/qt-5/qfiledialog.html#Option-enum
                );

    qDebug() << fileName << Qt::endl;

};

void MainWindow::button1(){
    qDebug("getOpenFileNames");

    // getOpenFileNamesの使い方

    // 1.filterの指定
    // 書式は次のとおり
    // 見出し(拡張子1 拡張子1)
    QString Filter1 = tr("all(*.*);;text(*.txt);;script(*.sh)");
    QString selFilter = tr("text(*.txt)");
    QString title = tr("Open a File");


    // こんな使う方あるの知らんかった。。。
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);

    QStringList fileName = dialog.getOpenFileNames(
                // 親
                this,
                // タイトル
                title,
                // デフォルトパス
                "C:/",
                // 表示する拡張子の指定
                Filter1,
                // dialog表示に選択しているフィルター
                &selFilter
                // オプション
                // https://doc.qt.io/qt-5/qfiledialog.html#Option-enum
                );

    foreach(QString name , fileName)
    qDebug() << name << Qt::endl;

};

void MainWindow::button2(){
    qDebug("getSaveFileName");


    // getOpenFileNamesの使い方

    // 1.filterの指定
    // 書式は次のとおり
    // 見出し(拡張子1 拡張子1)
    QString Filter1 = tr("all(*.*);;text(*.txt);;script(*.sh)");
    QString selFilter = tr("text(*.txt)");
    QString title = tr("Save a File");

    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);

    QString fileName = dialog.getSaveFileName(
                // 親
                this,
                // タイトル
                title,
                // デフォルトパス
                ".",
                // 表示する拡張子の指定
                Filter1,
                // dialog表示に選択しているフィルター
                &selFilter
                // オプション
                // https://doc.qt.io/qt-5/qfiledialog.html#Option-enum
                );

    qDebug() << fileName << Qt::endl;
};
void MainWindow::button3(){
    qDebug("getExistingDirectory");

    // https://doc.qt.io/qt-5/qfiledialog.html#getExistingDirectory
    // manualを見る限り、QFileDialog::ShowDirsOnlyは指定する必要がある。

    QFileDialog::Options options =
          QFileDialog::ShowDirsOnly;

    QString title = tr("Select a directory");

    QFileDialog dialog(this);

    QString fileName = dialog.getExistingDirectory(
                // 親
                this,
                // タイトル
                title,
                // デフォルトパス
                ".",
                // オプション
                options
                );

    qDebug() << fileName << Qt::endl;
};

void MainWindow::button4(){
    qDebug("QColorDialog");

    QColorDialog dialog(this);

    QColor color = dialog.getColor(
        "",
        this,
        tr("Select col")
    );

    dialog.getColor(
            "",
            this,
            tr("Select col"),
            QColorDialog::ShowAlphaChannel
        );

};

#include <QFontDialog>

void MainWindow::button5(){
    qDebug("QFontDialog");

    bool isFontSet;

    QFont font = QFontDialog::getFont(
        &isFontSet,
        QFont(""),
        this,
        tr("Select a font")
    );
}

#include <QInputDialog>

void MainWindow::button6()
{
    qDebug("QInputDialog");

    QInputDialog dialog(this);

    bool isSet;

    double value = dialog.getDouble(
        this,
        tr("double precision"),
        tr("value:"),
        // デフォルト値
        10,
        // 最小値
        -10000,
        // 最大値
        10000,
        // 小数点
        4,
        &isSet
    );

    int valueInt = dialog.getInt(
        this,
        tr("Integer"),
        tr("value:"),
        25,
        // 最小値
        0,
        // 最大値
        100,
        // ステップ
        1,
        &isSet
    );

    QStringList items;
    items << tr("A") << tr("B") << tr("C") << tr("D");

    QString item = dialog.getItem(
        this,
        tr("title ABCD"),
        tr("select:"),
        items,
        // 初期位置
        0,
        // 編集可能か
        true,
        &isSet
    );

    QString text = dialog.getMultiLineText(
        this,
        tr("multiline test"),
        tr("test:"),
        tr("this is\n a pen"),
        &isSet
    );

    QString text2 = dialog.getText(
        this,
        tr("text1"),
        tr("text2"),
        QLineEdit::Normal,
        tr("hogehoge"),
        &isSet
    );
}

#include <QMessageBox>

void MainWindow::button7()
{
    qDebug("QMessageBox");

    QMessageBox box(this);

    box.information(this, tr("information"), tr("hogehoge"));
    box.warning(this, tr("warning"), tr("message"));
    box.critical(this, tr("critical"), tr("oops"));
    int button = box.question(this, tr("check"), tr("ok?"));

    // 複数のボタンを作る場合
    // https://doc.qt.io/qt-5/qmessagebox.html#StandardButton-enum

    QMessageBox::StandardButtons button2 = QMessageBox::Ok | QMessageBox::Cancel;

    QMessageBox box2(this);


    box2.setIcon(QMessageBox::Question);
    box2.setWindowTitle(tr("title"));
    box2.setText(tr("check"));
    box2.setStandardButtons(button2);
    box2.setDefaultButton(QMessageBox::Cancel);
    box2.setButtonText(QMessageBox::Yes, tr("For"));
    box2.setButtonText(QMessageBox::Cancel, tr("Bye"));
    int button3 = box2.exec();

}
