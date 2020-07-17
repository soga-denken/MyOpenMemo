// 参考: https://stackoverflow.com/questions/19138100/how-to-draw-control-with-qstyle-and-with-specified-qss

// うまく動かないのでもう少し勉強が必要。。。

#include "mainwindow.h"

#include <QApplication>
#include <QStylePainter>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();

    //QCheckBox *cb = new QCheckBox( &w );
    //cb->move( 10, 30 );

    QStylePainter p(w);

    QStyleOptionButton opt;
    opt.init(w);
    opt.state |= QStyle::State_On;
    opt.state |= QStyle::State_Enabled;
    opt.rect = QRect( 10, 10, 40, 40 );

    QCheckBox cb; // create fake checkbox
    p.setPen(w->palette().light().color());
    p.drawPrimitive( QStyle::PE_IndicatorCheckBox, opt);

    w->update();
    w->show();
    return a.exec();
}
