#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include<QMessageBox>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void myTimeout();
    void setFlag(bool flag = true);

signals:
    void mySignal();

public slots:

private:
    bool isStop;
};

#endif // MYTHREAD_H
