#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include<QtDebug>
#include<QDialog>
#include<QFileDialog>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *pMenubar = new QMenuBar(this);
    QMenu* pMenu = pMenubar ->addMenu("port");
    QAction *pAction = pMenu->addAction("DIALOG");
    connect(pAction, &QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() << "112233";
            }
            );
    QMenu* p1 = pMenubar ->addMenu("port");
    QAction *p1Action = p1->addAction("none DIALOG");
    connect(p1Action, &QAction::triggered,
            [=]()
            {
             //     QDialog dlg;
               // dlg.show();
        QDialog *p = new QDialog(this);
        p->setAttribute((Qt::WA_DeleteOnClose));
        p -> show();
                qDebug() << "ewrewr";
            }
            );


    QMenu* p3 = pMenubar ->addMenu("tyu");
     QAction *p3Action = p3->addAction("none DIALOG");
    connect(p3Action, &QAction::triggered,
            [=]()
            {
               int ret = QMessageBox::question(this, "question", "are you ok?", QMessageBox::Ok | QMessageBox::Cancel);
                switch(ret)
               {
                case QMessageBox::Ok:
                    qDebug() << "i am ok";
                case QMessageBox::Cancel:
                    qDebug() << " i am bad";

               }
              //  QMessageBox::about(this, "about", "about qt");
                qDebug() << "message box";
            }
            );




    QMenu* p5 = pMenubar ->addMenu("port");
    QAction *p5Action = p5->addAction("none DIALOG");
    connect(p5Action, &QAction::triggered,
            [=]()
            {
                QString path =  QFileDialog::getOpenFileName(this, "open", "../","souce(*.cpp *.h);;text(*.txt);;all(*.*)");
                qDebug() << path;
            }
            );




}


MainWindow::~MainWindow()
{
    delete ui;
}

