#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            [=]()
    {
        static int i = 0;
        i++;
        ui->lcdNumber->display(i);
    }
            );
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_start_stop_clicked()
{
    if(timer->isActive() == false)
    {
        timer->start(100);// 100ms triggle timeout()
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(timer->isActive() == true)
    {
        timer->stop();// 100ms triggle timeout()
    }
}
