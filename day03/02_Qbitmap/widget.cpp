#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QBitmap>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    paintEvent()
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
//    QPainter p(this);
//    p.drawPixmap(0,0,QPixmap("../image/1.jpeg"));
//    p.drawPixmap(200,0,QBitmap("../image/1.jpeg"));
//    QPixmap pixmap;
//    pixmap.load("../image/7.jpeg");
//    p.drawPixmap(200,300,pixmap);
    QPixmap pixmap;
    QPainter p(&pixmap);
    pixmap.fill(Qt::white);
    p.drawPixmap(0,0,80,80,QPixmap("../image/4.jpeg"));
    pixmap.save("../pixmap.png");

    update();
}
