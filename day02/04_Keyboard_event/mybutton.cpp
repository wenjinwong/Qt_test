#include "mybutton.h"
#include<QMouseEvent>
#include<QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *e)
{
    e->ignore();

    if(e->button() == Qt::LeftButton)
    {
        //no deal
        qDebug() << "press left";
        e->ignore();
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
    QPushButton::mousePressEvent(e);

}
