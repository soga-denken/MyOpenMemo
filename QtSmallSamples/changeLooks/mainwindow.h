#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication * app, QWidget *parent = nullptr);
    ~MainWindow();

    QApplication * _app;
    QStyle *style;

private:
    Ui::MainWindow *ui;

public slots:
    void windows();
    void fusion();
    void defaultStyle();
};
#endif // MAINWINDOW_H
