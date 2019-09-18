#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include<QMouseEvent>
#include<QTimerEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *e);
    void mousePressEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *);
  //  bool event(QEvent *);
    //void messageBox(QMess)
private:
    int timerId;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
