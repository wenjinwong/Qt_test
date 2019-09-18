#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPixmap>
#include<QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p;
    //QPainter p(this);
    p.begin(this);
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::Dense1Pattern);
    p.setBrush(brush);
   // p.drawPixmap(0, 0, width(), height(), QPixmap("../image/4.jpeg"));
   // p.drawPixmap(rect(),QPixmap("../image/4.jpeg"));
    p.drawLine(50,50,150,150);
    p.drawLine(100,100,0,100);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(Qt::red);
    p.setPen(pen);
    p.drawRect(159,159,100,59);
    p.drawEllipse(QPoint(150, 150),30,23);
    p.drawPixmap(x,200,80,80,QPixmap("../image/3.jpeg"));

    p.end();



}

void Widget::on_pushButton_clicked()
{
    x += 20;
    if(x > width()) x =0;
    //flush windoww
    update();
}
