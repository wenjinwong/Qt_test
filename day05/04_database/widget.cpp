#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlDriver>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
}

Widget::~Widget()
{
    delete ui;
}

