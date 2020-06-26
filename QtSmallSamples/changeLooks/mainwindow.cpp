#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPushButton>
#include <QStyleFactory>
#include <QDebug>

MainWindow::MainWindow(QApplication * app, QWidget *parent)
    : QMainWindow(parent)
    , _app(app)
    , style(_app->style())
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Button1, &QPushButton::clicked,
            this, &MainWindow::windows);
    connect(ui->Button2, &QPushButton::clicked,
            this, &MainWindow::fusion);
    connect(ui->Button3, &QPushButton::clicked,
            this, &MainWindow::defaultStyle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::windows()
{
    qDebug() << "windows";

    QStyle * ptr2 = QStyleFactory::create("windows");
    _app->setStyle(ptr2);
}

void MainWindow::fusion()
{
    qDebug() << "fusion";

    QStyle * ptr2 = QStyleFactory::create("fusion");
    _app->setStyle(ptr2);
}

void MainWindow::defaultStyle()
{
    qDebug() << "default";
    QStyle * ptr2 = QStyleFactory::create("windowsvista");
    _app->setStyle(ptr2);
}
