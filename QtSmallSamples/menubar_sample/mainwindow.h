#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// includeしないためのforward declaration
QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void menu();

private:
    QLabel *infoLabel;
};
#endif // MAINWINDOW_H
