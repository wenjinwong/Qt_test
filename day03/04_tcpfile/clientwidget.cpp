#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QDebug>
#include<QMessageBox>
#include<QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);

    isStart = true;

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
                {
                    QByteArray buf = tcpSocket->readAll();
                    //get content
                    if(true == isStart)
                    {
                        isStart = false;
                        //parse head

                        //init
                        // open file

                        fileName = QString(buf).section("##", 0, 0);
                        fileSize = QString(buf).section("##", 1, 1).toInt();
                        recvSize = 0;

                        file.setFileName(fileName);
                        bool isOk = file.open(QIODevice::WriteOnly);
                        if(false == isOk)
                        {
                            qDebug() << "writeonly error 40";
                        }

                    }
                    else
                    {
                        qint16 len = file.write(buf);
                        recvSize += len;
                        if(recvSize == fileSize)
                        {
                            file.close();
                            QMessageBox::information(this, "complete", "file receive complete");
                            tcpSocket->disconnectFromHost();
                            tcpSocket->close();
                        }
                    }
                }
            );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_pushButton_clicked()
{
    //server ip port
    QString ip = ui->lineEdit_ip->text();
    unsigned int port = ui->lineEdit_port->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip), port);
    qDebug() << "connected";
}











