#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    //hen fu zha de shu ju chuli xu yao hao shi 5miao
    sleep(5);
    emit isDone();
}
