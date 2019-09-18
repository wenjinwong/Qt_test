#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QHostAddress>
#include<QTcpSocket>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpSocket = nullptr;
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
    {
        ui->textEdit_2->setText("connected ");
    }
            );
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        //handle readmsg
        QByteArray array = tcpSocket->readAll();
        ui->receive->append(array.data());
    }
            );

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_connect_clicked()
{
    //get server port ip
    QString ip = ui->lineEdit->text();
    qint16 port = ui->lineEdit_2->text().toInt();
    //connect to server
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void ClientWidget::on_send_clicked()
{
    QString str = ui->textEdit_2->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}

void ClientWidget::on_close_clicked()
{
    //disconnect

    tcpSocket->disconnectFromHost();
    tcpSocket->close();

}
