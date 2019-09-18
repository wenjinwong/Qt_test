#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include<QAbstractAnimation>
#include<QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setTextMargins(5,10,4,0);
  //  ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setText("hello");

    QStringList list;
    list << "hEllo" << "how are you" << "hehe";
    QCompleter *com = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);
    QString str = ui->lineEdit->text();
    qDebug() << str;

    ui->labelText->setText("text");
    ui->labelImage->setPixmap(QPixmap("://7.jpeg"));
    QMovie *myMovie = new QMovie("://7.jpeg");
    myMovie->start();
    ui->labelGif->setMovie(myMovie);
    ui->labelUrl->setText("<h1 ><a href=\"https://www.baidu.com\">hello</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);
    ui->lcdNumber->display(123);
    ui->progressBar->setValue(100);
    ui->progressBar->setMaximum(200);
    ui->progressBar->setMinimum(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
