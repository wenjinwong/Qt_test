#include "mylable.h"
#include<QLabel>
#include<QMouseEvent>
MyLable::MyLable(QWidget *parent) : QLabel(parent)
{

}

void MyLable::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    QString text = QString("<center><h1>mouse press: (%1, %2) </h1></center>").arg(i).arg(j);
    this->setText(text);

}

void MyLable::mouseReleaseEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    QString text = QString("<center><h1>mouse press: (%1, %2) </h1></center>").arg(i).arg(j);
    this->setText(text);

}

void MyLable::mouseMoveEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    QString text = QString("<center><h1>mouse press: (%1, %2) </h1></center>").arg(i).arg(j);
    this->setText(text);

}
