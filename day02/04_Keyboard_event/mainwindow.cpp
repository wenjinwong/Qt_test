#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>
#include<QDebug>
#include<QTimerEvent>
#include<QPushButton>
#include<QMessageBox>
#include<QMouseEvent>
#include<QEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerId = this->startTimer(1000);//ms 1sec
    connect(ui->pushButton, &MyButton::clicked,
            [=]()
    {
        qDebug() << "the button is pressed";
    }

            );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << (char)e->key();
    if(e->key() == Qt::Key_A)
    {
        qDebug() << "press A";
    }
}

void MainWindow::timerEvent(QTimerEvent *e)
{
//    static int sec = 0;
//    sec ++;
//    ui->label->setText(
//                QString("timer ou : %1").arg(sec++)
//                       );
//    if(5 == sec || 6 == sec || 7 == sec)
//    {
//        this->killTimer(timerId);
//    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    int ret = QMessageBox::question(this, "question", "close window?");
    if(ret == QMessageBox::Yes)
    {
        //close no pass event
        e->accept();
    }
    else
    {
        e->ignore();
    }
}

//bool MainWindow::event(QEvent *e)
//{
//    if(e->type() == QEvent::Timer)
//    {
//        QTimerEvent *env = static_cast<QTimerEvent *>(e);
//        timerEvent(env);
//        return true;
//    }
//    else{
//       return MainWindow::event(e);
//    }

//}

void MainWindow::mousePressEvent(QMouseEvent *)
{
    qDebug() << "+++++++++++";
}


