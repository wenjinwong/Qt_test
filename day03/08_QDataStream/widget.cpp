#include "widget.h"
#include "ui_widget.h"
#include<QDataStream>
#include<QFile>
#include<QtDebug>
#include<QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    QFile file("../test.txt");
    bool isOk = file.open(QIODevice::WriteOnly);
    if(isOk)
    {
        //put data into file
        QDataStream stream(&file);
        stream << QString("some data") << 250;
        file.close();

    }
//    QFile file1("../ee.txt");
//    bool isOk1 = file.open(QIODevice::WriteOnly);
//    if(isOk1)
//    {
//        //put data into file
//        QTextStream stream1(&file1);
//        stream1 << QString("some data") << 250;
//        file1.close();

//    }

}

void Widget::readData()
{
    QFile file("../test.txt");
    bool isOk = file.open(QIODevice::ReadOnly);
    if(isOk)
    {
        //put data into file
        QDataStream stream(&file);
        QString str;
        int a;
        stream >> str >> a;
        qDebug() << str << a;
        file.close();

    }
}
