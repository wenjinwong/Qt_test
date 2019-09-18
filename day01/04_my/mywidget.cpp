#include "mywidget.h"
#include <QDebug>
#include "mybutton.h"
MyWidget::MyWidget(QWidget *parent)
    : QMainWindow(parent)
{
    MyButton *b3 = new MyButton(this);
    b3->setText("123");
    //NO NEED TO DELETE OBJ BY HAND
    //dir or indir inherit from qobj
}

MyWidget::~MyWidget()
{
}

