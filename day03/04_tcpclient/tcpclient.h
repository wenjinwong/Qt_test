#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include<QTcpSocket>
#include<QTcpServer>
QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TcpClient *ui;
    QTcpSocket* tcpSocket;
};
#endif // TCPCLIENT_H
