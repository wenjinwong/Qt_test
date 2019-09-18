#include "widget.h"
#include "ui_widget.h"
#include<QImage>
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(599,500);
    QImage image(400,400, QImage::Format_ARGB32);
    QPainter p;
    p.begin(&image);
    p.drawImage(0,0,QImage("../image/7.jpeg"));
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            image.setPixel(QPoint(i,j), qRgb(0,255,34));
            image.pixel(QPoint(i,j));
        }
    }
    p.end();
    image.save("../test.jpeg");
}

Widget::~Widget()
{
    delete ui;
}

