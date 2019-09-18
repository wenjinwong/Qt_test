#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("worker");
    b4.setParent(this);
    b4.setText("switch to main");
    b4.move(59,59);
    connect(& b4, &QPushButton::clicked, this, &SubWidget::sendSlot);
    resize(500,500);

}

void SubWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250, "i am sub");
}
