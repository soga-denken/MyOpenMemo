#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::onClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClicked(){

    MyDialog * dialog = new MyDialog(this);

    dialog->exec();

    delete dialog;
}
