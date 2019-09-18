#include "mythread.h"
#include<QThread>
#include<QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;

}

void MyThread::myTimeout()
{
    while (1) {
        QThread::sleep(1);
        emit mySignal();
         //QMessageBox::a.boutQt(nullptr);
        qDebug() << "sub thread id:" << QThread::currentThread();
        if(isStop == true) break;

    }

}

void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
