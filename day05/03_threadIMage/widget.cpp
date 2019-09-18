#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include"mythread.h"
#include<QThread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myT = new MyThread;
    thread = new QThread(this);
    myT->moveToThread(thread);

    thread->start();


    connect(ui->pushButton, &QPushButton::pressed, myT, &MyThread::drawImage);
    connect(myT, &MyThread::updateImage, this, &Widget::getImage);
    connect(this, &Widget::destroyed, this, &Widget::dealClose);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{

    QPainter p(this);
    p.drawImage(50,50,image);
}

void Widget::getImage(QImage temp)
{
    image = temp;
    update();
}

void Widget::dealClose()
{
    //exit thread

    thread ->quit();

    //huishou
    thread->wait();

    delete myT;
}
