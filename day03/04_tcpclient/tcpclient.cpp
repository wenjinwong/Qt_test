#include "tcpclient.h"
#include "ui_tcpclient.h"

TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    QTcpSocket* tcpSocket = new QTcpSocket(this);


//    QString ip = ui->ip->text();
//    QHostAddress hostAdress(ip.toUtf8().data());
//    int port = ui->port->text().toInt();
//    bool ret = tcpSocket->bind(hostAdress, port);
//    if(ret)
//    {
//        QString str("ip:{%1}  port:{%2}");

//        ui->read->append(str.arg(ip).arg(port));
//        update();

//    }
}

TcpClient::~TcpClient()
{
    delete ui;
}


void TcpClient::on_pushButton_clicked()
{
    QString ip = ui->ip->text();
    QHostAddress hostAdress(ip.toUtf8().data());
    int port = ui->port->text().toInt();
    bool ret = tcpSocket->bind(hostAdress, port);
    if(ret)
    {
        QString str("ip:{%1}  port:{%2}");

        ui->read->append(str.arg(ip).arg(port));
    }
    QString msg(ui->send->text());

    tcpSocket->write(msg.toUtf8().data());

}
