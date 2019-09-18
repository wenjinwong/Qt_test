#include "serverwidget.h"
#include "ui_serverwidget.h"
#include<QHostAddress>
#include<QFileDialog>
#include<QDebug>
#include<QTimer>


ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress("127.0.0.1"), 8888);
    setWindowTitle("8888");
    ui->pushButto_select->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    timer = new QTimer(this);
    timer->start(20);
    tcpSocket = new QTcpSocket(this);
    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
    {
        tcpSocket = tcpServer->nextPendingConnection();
        QString ip = tcpSocket->peerAddress().toString();
        unsigned short port = tcpSocket->peerPort();
        QString str = QString("{%!:%2} connected successful").arg(ip).arg(port);
        ui->textEdit->setText(str);
        ui->pushButton_2->setEnabled(true);
        ui->pushButto_select->setEnabled(true);

    }
            );
    connect(timer, &QTimer::timeout,
            [=]()
    {
        timer->stop();
        sendData();
    }
            );
}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_pushButto_select_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open","../");
    if(false == path.isEmpty())
    {
        //get file msg
        //readonly to open file
        fileName.clear();
        fileSize = 0;
        QFileInfo info(path);
        fileName = info.fileName();
        fileSize = info.size();
        sendSize = 0;

        QFile file(path);
        file.setFileName(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk == false)
        {
            qDebug() << "readonly open fail";
        }
        ui->textEdit->append(path);
        ui->pushButto_select->setEnabled(false);
        ui->pushButto_select->setEnabled(true);

    }
    else
    {
        qDebug() << "fail to open file path";
    }
}

void ServerWidget::on_pushButton_2_clicked()
{
    //send head
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    qint64 len = tcpSocket->write(head.toUtf8());
    if(len > 0)
    {
        timer->start(20);
        qDebug() << "send head complete";

    }
    else
    {
        qDebug() << " send head failed";
        file.close();
        ui->pushButto_select->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }
    //send body
}


void ServerWidget::sendData()
{
    qint64 len = 0;
    do
    {
        char buf[4*1024] = {0};
        len =file.read(buf, sizeof(buf));
        tcpSocket->write(buf, len);
        sendSize += len;


    }while(len > 0);
    if(sendSize == fileSize)
    {
        ui->textEdit->setText("file sended successful");
        file.close();
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }
}












