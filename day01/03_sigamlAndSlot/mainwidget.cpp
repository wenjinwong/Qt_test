#include "mainwidget.h"
#include <QPushButton>
#include<QDebug>
MainWIdget::MainWIdget(QWidget *parent)
    : QWidget(parent)
{
   b1.setParent(this);
   b1.setText("close");
   b1.move(100,100);

   b2 = new  QPushButton(this);
   b2->setText("abc");

   connect(&b1, &QPushButton::pressed, this, &MainWIdget::close);
   /*
    * sender
    * signal
    * receiver
    * handletf
    */

   /*
    * define slot
    * func glabal func static func
    * signal have no retuan value,so void slot()
    */

   connect(&b1, &QPushButton::released, this, &MainWIdget::mySlot);
   connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

   setWindowTitle("boss");
   //this->setWindowTitle("boss");
   b3.setParent(this);
  b3.setText("switch to sub");
  b3.move(300,200);
//  s.show();
 // connect(&b3,&QPushButton::released, &s, &SubWidget::show);
  //connect(&b3,&QPushButton::released, this, &MainWIdget::hide);
    void (SubWidget::*func)() = &SubWidget::mySignal;
    void (SubWidget::*fun)(int, QString) = &SubWidget::mySignal;
    connect(&b3, &QPushButton::pressed, this, &MainWIdget::changeWin);
    connect(&s, func, this, &MainWIdget::dealSub);
   connect(&s, fun, this, &MainWIdget::dealSlot);

   /*
    * lambda
    *
    */
  QPushButton *b5 = new QPushButton(this);
  b5->setText("lambda");
  b5->move(399,100);
  QString s = "pppp";
  connect(b5, &QPushButton::released,this,
          [=]()mutable//= all var put pass by value
  // this : class member pass by value
          //&all outside val referrence tocken
  {
      qDebug() << s;
  }
          );
 resize(500,500);

}

MainWIdget::~MainWIdget()
{
}
void MainWIdget::mySlot()
{
    b2->setText("123");
}

void MainWIdget::changeWin()
{
    //sub show
    s.show();
    this->hide();
}

void MainWIdget::dealSub()
{

    s.hide();
    show();
}
void MainWIdget::dealSlot(int a, QString str)
{
    qDebug() << a << str.toUtf8().data();
}
