#include "smallwidget.h"
#include<QSlider>
#include<QHBoxLayout>
#include <QSpinBox>
#include<QAction>
SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);
    int i = spin->value();

    connect(spin,  QOverload<int>::of(&QSpinBox::valueChanged),
            [=]()
    {
        int i = spin->value();
        slider->setValue(i);
    }
            );
    setLayout(hLayout);
}
