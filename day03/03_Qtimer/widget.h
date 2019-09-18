#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_start_stop_clicked();

    void on_pushButton_2_clicked();

private:
    QTimer *timer;
    Ui::Widget *ui;
};
#endif // WIDGET_H
