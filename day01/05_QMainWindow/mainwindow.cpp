#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include<QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //menu bar
    QMenuBar *mBar = menuBar();
    //file
    QMenu *pFile = mBar->addMenu("file");
    //add menu terms, add action
    QAction *pNew = pFile->addAction("new");

    connect(pNew, &QAction::triggered,
            [=]
    {
        qDebug() << "new is pressed";
    }
            );

    pFile->addSeparator();

    QAction *pOpen = pFile->addAction("open");
    connect(pOpen, &QAction::triggered,
                [=]
    {
        qDebug() << "open is pressed";
    }

                );
    //tool bar
    QToolBar *toolBar = addToolBar("toolBar");
    QAction *pClean = toolBar->addAction("clean");
    connect(pClean, &QAction::triggered,
            [=]
    {
        qDebug() << "clean is pressed";
    }
            );

    QPushButton *b = new QPushButton(this);
    b->setText("save");
    toolBar->addWidget(b);
    connect(b, &QPushButton::clicked,
            [=]()
    {
        b->setText("saved something");
        //this->hide();
    }
            );

    //status bar
    QStatusBar *sBar = statusBar();
    QLabel *label = new QLabel (this);
    label->setText("Normal text file");
    sBar->addWidget(label);
    sBar->addWidget(new QLabel("2", this));
    sBar->addPermanentWidget(new QLabel("3", this));


    //core control bar
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);


    //float window
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock );

    QTextEdit *textEdit1 = new QTextEdit(this);
    dock->setWidget((textEdit1));

    resize(500, 500);
}

MainWindow::~MainWindow()
{
}

