#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QTime>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("ADKM LCD");
    resize(300,200);

    QHBoxLayout *hbox= new QHBoxLayout(this);

    lcd = new QLCDNumber(this);
    lcd->setFont(QFont("Times",15));
    lcd->setStyleSheet("background-color:yellow");

    hbox->addWidget(lcd);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()) , this , SLOT(showTime()));

    showTime();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");

    if((time.second() % 2 == 0))
        text[2] = ' ';
    lcd->display(text);
}
