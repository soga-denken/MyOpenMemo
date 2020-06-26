#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void button0();
    void button1();
    void button2();
    void button3();
    void button4();
    void button5();
    void button6();
    void button7();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
