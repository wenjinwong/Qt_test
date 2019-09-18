#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPushButton>
#include"subwidget.h"
class MainWIdget : public QWidget
{
    Q_OBJECT

public:
    MainWIdget(QWidget *parent = nullptr);
    ~MainWIdget();
    void mySlot();
    void changeWin();
    void dealSub();
    void dealSlot(int, QString);


private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    SubWidget s;
};
#endif // MAINWIDGET_H
