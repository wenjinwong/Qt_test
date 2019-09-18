#ifndef SUBWIDGET_H
#define SUBWIDGET_H
#include<QPushButton>
#include <QWidget>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void sendSlot();
signals:
    /*
     * no return
     * can have parameter
     * signal to decelar
     *
     */
    void mySignal();
   void mySignal(int, QString);//can oveload
public slots:

public:
    QPushButton b4;
};

#endif // SUBWIDGET_H
