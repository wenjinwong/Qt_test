#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWIdget w;//exec it is constructor
    w.show();
    return a.exec();
}
