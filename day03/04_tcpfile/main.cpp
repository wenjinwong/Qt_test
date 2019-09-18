#include "serverwidget.h"

#include <QApplication>
#include"clientwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWidget w;
    w.show();
    ClientWidget s;
    s.show();
    return a.exec();
}
