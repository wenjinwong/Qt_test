#include "mythread.h"
#include<QPainter>
#include<QRandomGenerator>
#include<QPoint>
#include<QPen>
#include<QBrush>
#include<QThread>

MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::drawImage()
{
    QImage image(500, 500, QImage::Format_ARGB32);
    QPainter p(&image);


    QPen pen;
    pen.setWidth(5);
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    p.setPen(pen);
    p.setBrush(brush);

    QPoint a[] =
    {
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
    };
    p.drawPolygon(a, 5);
    QThread::sleep(2);
    emit updateImage(image);

}
