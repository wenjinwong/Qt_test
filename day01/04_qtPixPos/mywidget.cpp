#include "mywidget.h"
#include<QPushButton>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    move(0,0);//main window reference screen
    QPushButton* b1 = new QPushButton(this);
    b1->move(0,0);
    b1->setText("hello");
    b1->resize(200,100);
    QPushButton* b2 = new QPushButton(b1);
    b2->move(0,0);
    b2->setText("hello");
    b2->resize(50,50);
}

MyWidget::~MyWidget()
{
}

