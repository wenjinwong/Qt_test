#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();


private slots:
    void on_pushButton_2_clicked();

    void on_send_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer *tcpServer;//lister
    QTcpSocket *tcpSocket;//communication
};
#endif // SERVERWIDGET_H
