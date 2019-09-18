#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    setAttribute(Qt::WA_TranslucentBackground);
    QPainter p;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
QPainter p(this);p.drawPixmap(0,0,QPixmap("../image/2.jpeg"));

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        close();
    }
    else if(event->button() == Qt::LeftButton)
    {
        move(event->x(), event->y());

    }
}
