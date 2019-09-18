#include "mywidget.h"
#include "ui_mywidget.h"
#include<QThread>
#include<QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    myT = new MyThread();
    thread = new QThread(this);

    myT->moveToThread(thread);
    connect(myT, &MyThread::mySignal, this, &MyWidget::dealSignal);
    connect(this, &MyWidget::startThread, myT, &MyThread::myTimeout);
    connect(this, &MyWidget::destroyed, this, &MyWidget::dealClose);
    qDebug() << "thread id:" << QThread::currentThread();

}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::dealClose()
{
    on_pushButton_2_clicked();
    delete myT;
}

void MyWidget::on_pushButton_clicked()
{
    //start thread with no handle
    if(thread->isRunning() == true)
        return;
    thread->start();
    //myT->myTimeout();
    emit startThread();
}

void MyWidget::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void MyWidget::on_pushButton_2_clicked()
{
    if(thread->isRunning() == false)
        return;
    myT->setFlag(true);
    thread->quit();
    thread->wait();
}
