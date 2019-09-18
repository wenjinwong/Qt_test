#include "mmywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //noly one app
    QApplication a(argc, argv);
    //derived form QWidgth is a window
    //w is a window
    mMyWidget w;
    //window is hidden in  default
    w.show();
    //let app run forever until user's implement
    return a.exec();
}
