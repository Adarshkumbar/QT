#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout *hbox = new QHBoxLayout(this);

    QLabel *label = new QLabel();
    label->setText("Spinner Text");
    label->setFont(QFont("Ariel",20));

    price = new QLineEdit();
    price->setFont(QFont("Times",15));

    total = new QLineEdit();
    total->setFont(QFont("Times",15));

    spinBox = new QSpinBox();
    spinBox->setFont(QFont("Times",15));

    connect(spinBox,SIGNAL(valueChanged(int)) , this , SLOT(changeSpin()));

    hbox->addWidget(label);
    hbox->addWidget(price);
    hbox->addWidget(spinBox);
    hbox->addWidget(total);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeSpin()
{
    int myprice = price->text().toInt();
    int totaPrice =spinBox->value() * myprice;
    total->setText(QString::number(totaPrice));
}
