#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel{color:red;}");
    ui->pushButton->setStyleSheet("QPushButton{color:green;}""QPushButton::hover{color:red;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

