#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isConnected(false)
{
    ui->setupUi(this);

    connect(ui->Button1, &QPushButton::clicked, this, &MainWindow::dynamicConnect);
    connect(ui->Button2, &QPushButton::clicked, this, &MainWindow::dynamicDisconnect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dynamicConnect(){

    if(!isConnected){
        qDebug("connecting");
        connect(ui->Button3,&QPushButton::clicked, this, &MainWindow::run);
        isConnected = true;
    }
    else
    {
        qDebug("already connected");
    }
}

void MainWindow::dynamicDisconnect(){

    if(isConnected){
        qDebug("disconnecting");
        disconnect(ui->Button3,&QPushButton::clicked, this, &MainWindow::run);
        isConnected = false;
    }
    else
    {
        qDebug("already disconnected");
    }


}

void MainWindow::run(){
    qDebug("run");
}
