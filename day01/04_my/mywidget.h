#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>

class MyWidget : public QMainWindow
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
};
#endif // MYWIDGET_H
