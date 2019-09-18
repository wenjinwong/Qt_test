#ifndef MYLABLE_H
#define MYLABLE_H

#include <QWidget>
#include<QLabel>

class MyLable : public QLabel
{
    Q_OBJECT
public:
    explicit MyLable(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent *ev) ;
    void mousePressEvent(QMouseEvent *ev) ;
    void mouseReleaseEvent(QMouseEvent *ev) ;

signals:

public slots:
};

#endif // MYLABLE_H
