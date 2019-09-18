#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    setWindowTitle("server **** 8888");
    tcpServer = nullptr;
    tcpSocket = nullptr;
    tcpServer = new QTcpServer(this);//parent let it free mem auto
    tcpServer->listen(QHostAddress::Any, 8888);
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        //get connected socket
        tcpSocket = tcpServer->nextPendingConnection();
        //get client ip port
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString temp = QString("{%1:%2}:connect success").arg(ip).arg(port);
        ui->textEditRead->setText(temp);

        connect(tcpSocket, &QTcpSocket::readyRead,
                [=]()
        {
            QByteArray array = tcpSocket->readAll();

            ui->textEditRead->append(array);
        }
                );
    }
            );

}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_send_clicked()
{
    if(nullptr == tcpServer || nullptr == tcpSocket) return;
    if(tcpServer->hasPendingConnections())
    {
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }

    //close();
}


void ServerWidget::on_pushButton_2_clicked()
{
    if(nullptr == tcpSocket) return;
    //get textfile content
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}
