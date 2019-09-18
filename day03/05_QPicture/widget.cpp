#include "widget.h"
#include "ui_widget.h"
#include<QPicture>
#include<QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter p;

    p.begin(&picture);

    p.drawPixmap(0,0,80,80,QPixmap("../image/6.jpeg"));
    p.drawLine(0,0,100,100);
    p.end();
    picture.save("../picture.png");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::painEvent(QPaintEvent *e)
{
#if 0
    QPicture pic;
    pic.load("../picture.png");
    QPainter p(this);
    p.drawPicture(0,0,pic);
#endif
}
