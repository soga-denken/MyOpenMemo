#include "mainwindow.h"

// menuに必要
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    this->setCentralWidget(widget);

    infoLabel = new QLabel(tr("test"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    this->statusBar()->showMessage("yrdy");
}

MainWindow::~MainWindow()
{
}

void MainWindow::menu(){
    QString title1 = tr("File");

    QMenu* menu1 = new QMenu(title1, this);


}
