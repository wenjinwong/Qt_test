#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHostAddress>
#include<QIntValidator>
ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    //alloc parent
    udpSocket = new QUdpSocket(this);

    //bind
   // udpSocket->bind(9999);
    udpSocket->bind(QHostAddress::AnyIPv4, 8888);
    udpSocket->joinMulticastGroup(QHostAddress("224.0.0.2"));
    udpSocket->leaveMulticastGroup(QHostAddress("224.0.0.2"));
    setWindowTitle("port : 8888");

    // when target send msg
    //triggle
    connect(udpSocket, &QUdpSocket::readyRead,this, &ServerWidget::dealMsg);
    resize(300,300);
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::dealMsg()
{
    //handle msg
    char buf[1024];
    QHostAddress cliAddress;
    unsigned short port;
    qint16 len = udpSocket->readDatagram(buf, sizeof(buf), &cliAddress, &port);
    if(len > 0)
    {
        QString str = QString("{%1:%2} %3").arg(cliAddress.toString()).arg(port).arg(buf);
        ui->textEdit->setText(str);
        update();
    }
}

void ServerWidget::on_pushButton_send_clicked()
{
    //get target ip port
    unsigned short port = ui->lineEdit_port->text().toInt();
    qint16 ip = ui->lineEdit_ip->text().toInt();
    QString str = ui->textEdit->toPlainText();
    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);



}
