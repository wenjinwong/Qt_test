#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include<QFileDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open","../", "TXT(*.txt)");
    if(path.isEmpty() == false)
    {
        QFile file(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk)
        {
          //read and show
            QByteArray array = file.readLine(100);
            ui -> textEdit->setText(QString(array));

            QByteArray array1;
        }
    }
}

void Widget::on_pushButton_2_clicked()
{
    QString s =  QFileDialog::getSaveFileName(this, "save", "../", "TXT(.txt)");
    ui->textEdit->setText(s);
    QFile  file(s);
    file.open(QIODevice::WriteOnly);
    file.write(ui->textEdit->toPlainText().toStdString().data(), 5);
}
