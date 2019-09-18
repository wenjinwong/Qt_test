#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QFile>
#include<QFileInfo>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();
    void sendData();

private slots:
    void on_pushButto_select_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::ServerWidget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QTimer *timer;
    QFile file;
    QString fileName;
    qint64 fileSize;
    qint64 sendSize;

};
#endif // SERVERWIDGET_H
