#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QImage>
#include"mythread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void getImage(QImage);//slot func
    void dealClose();

private:
    Ui::Widget *ui;
    QImage image;
    MyThread *myT;
    QThread *thread;
};
#endif // WIDGET_H
