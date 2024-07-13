#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn1 = new QPushButton();
    btn1->setText("Change Text");

    // bool isClicked = true;
    // creating connect which connects slots with signal
    connect(btn1,SIGNAL(clicked()),this,SLOT(changeText()));

// LABEL
    label = new QLabel(this);
    label->setText("This is LABEL ");

// RADIO BUTTONS
    radio1 = new QRadioButton(this);
    radio1->setText("C++");
    radio1->setFont(QFont("Times",15));
    radio1->setIcon(QIcon(":/images/cpp.png"));

    radio2 = new QRadioButton(this);
    radio2->setText("JavaScript");
    radio2->setFont(QFont("Times",15));
    radio2->setIcon(QIcon(":/images/js.png"));


    radio3 = new QRadioButton(this);
    radio3->setText("Python");
    radio3->setFont(QFont("Times",15));
    radio3->setIcon(QIcon(":/images/go.png"));

//Horizontal BOX
    QHBoxLayout *hBox= new QHBoxLayout(this);
    hBox->addWidget(btn1);
    // hBox->addWidget(label);

//Vertical BOX
    QVBoxLayout *vBox = new QVBoxLayout(this);
    vBox ->addWidget(label);
    hBox ->addWidget(radio1);
    hBox ->addWidget(radio2);
    hBox ->addWidget(radio3);

    vBox ->addWidget(hBox);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    // isClicked = !isClicked;

    // if(isClicked)
       // label->setText("This is LABEL ");
    // else
        label->setText("Label is Changed");
        label->setStyleSheet("color:red");
        label->setFont(QFont("Times",15));
}
