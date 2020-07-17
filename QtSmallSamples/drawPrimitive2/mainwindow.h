#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStyle>
#include <QPainter>
#include <QStyleOptionButton>
#include <QCheckBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    void paintEvent( QPaintEvent * event )
//    {
//        QPainter p( this );

//        QStyleOptionButton opt;
//        opt.state |= QStyle::State_On;
//        opt.state |= QStyle::State_Enabled;
//        opt.rect = QRect( 10, 10, 20, 20 );

//        QCheckBox cb(this); // create fake checkbox

//        style()->drawPrimitive( QStyle::PE_IndicatorCheckBox, &opt, &p, &cb);

//    }
};
#endif // MAINWINDOW_H
