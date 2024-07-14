#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout *hBox = new QHBoxLayout();
    label = new QLabel();

    label->setText("Choose Languages : ");
    label->setFont(QFont("Times",16));

    lineEdit = new QLineEdit();
    lineEdit->setFont(QFont("Times",16));

    hBox->addWidget(label);
    hBox->addWidget(lineEdit);
}

Widget::~Widget()
{
    delete ui;
}
