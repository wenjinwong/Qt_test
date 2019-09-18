#include "mybutton.h"
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "button is constructing";
}
MyButton::~MyButton()
{
    qDebug() << "button is deconstructor";
}
