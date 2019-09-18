 #include <QApplication>
#include<QtWidgets>
#include<QPushButton>
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget w;
//if not assem parent obj ,alone
    QPushButton b;
    b.setText("^ - ^");
    b.setParent((&w));
    b.move(100,100);
    QPushButton b1(&w);
    b1.setText("tittle");
    w.show();
    app.exec();
    return 0;
}
