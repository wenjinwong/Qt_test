#include "widget.h"
#include "ui_widget.h"
#include<QThread>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer.setParent(this);
    thread = new MyThread(this);

    //start timeout

    connect(&timer, &QTimer::timeout, this, &Widget::dealTimeout);
    connect(thread, &MyThread::isDone, this, &Widget::dealDone);

    // touch x, emit des
    connect(this, &Widget::destroyed, this, &Widget::stoopThread);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::stoopThread()
{
    thread->quit();
    thread->wait();
}


void Widget::dealTimeout()
{
    static int i =0;i++;
    ui->lcdNumber->display(i);
}



void Widget::on_pushButton_clicked()
{
    if(timer.isActive() == false)
    {
        timer.start(100);
    }

    //very complex handle

    thread->start();
}

void Widget::dealDone()
{
    qDebug() << "it is over";
    timer.stop();
}
















