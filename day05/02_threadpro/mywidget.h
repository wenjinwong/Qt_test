#ifndef MYWIDGET_H
#define MYWIDGET_H

#include<QThread>
#include <QWidget>
#include <mythread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void dealSignal();
    void dealClose();

signals:
    void startThread();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::MyWidget *ui;
    MyThread *myT;
    QThread *thread;

};
#endif // MYWIDGET_H
