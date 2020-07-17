#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QPrinter printer(QPrinter::ScreenResolution);
    QPrintDialog printDialog(&printer, &w);

    if(printDialog.exec() == QDialog::Accepted)//ＯＫなら印刷
       {
            QPainter painter(&printer);
            QRect rect = painter.viewport();
            QPixmap pixmap("C:/Zoom.jpg");
            QSize size = pixmap.size();
            size.scale(rect.size(), Qt::KeepAspectRatio);//縦横比維持

            // rect.x()は左上のx座標。横幅ではない。。。
            // rect.y()左上のy座標。立幅ではない。。。
            painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
            painter.setWindow(pixmap.rect());
            painter.drawPixmap(0, 0, pixmap);
        }
    return a.exec();
}
