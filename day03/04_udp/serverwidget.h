#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H
#include <QUdpSocket>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();
    void dealMsg();//slot function

private slots:
    void on_pushButton_send_clicked();

private:
    QUdpSocket * udpSocket;
    Ui::ServerWidget *ui;
};
#endif // SERVERWIDGET_H
