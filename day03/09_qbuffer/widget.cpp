#include "widget.h"
#include "ui_widget.h"
#include<QBuffer>
#include <QDebug>
#include<QByteArray>
#include<iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QByteArray array;
    QBuffer memFile(&array);
    memFile.open(QIODevice::ReadWrite);
    memFile.write("111111111111111gjh \n hhhhhhhhhh1111\n");
    char s[10];
    memFile.read(s, 10);
    std::cout<<s;
    qDebug() << memFile.buffer();
    qDebug() << "array" << array;
    memFile.close();
}

Widget::~Widget()
{
    delete ui;
}

