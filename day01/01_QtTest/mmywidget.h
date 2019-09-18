#ifndef MMYWIDGET_H
#define MMYWIDGET_H

#include <QWidget>

class mMyWidget : public QWidget
{
   //slot and signal need
    //Q_OBJECT

public:
    mMyWidget(QWidget *parent = nullptr);
    ~mMyWidget();
};
#endif // MMYWIDGET_H
