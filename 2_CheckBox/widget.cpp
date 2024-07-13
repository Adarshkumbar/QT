#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout *hbox = new QHBoxLayout();

    // Check boxes creation
    cb1 = new QCheckBox();
    cb1->setText("C++");
    cb1->setFont(QFont("Times",16));
    cb1->setIcon(QIcon(":/images/cpp.png"));
    cb1->setIconSize(QSize(40,40));

    connect(cb1,SIGNAL(stateChanged(int)),this,SLOT(changeCheckBox()));

    cb2 = new QCheckBox();
    cb2->setText("JS");
    cb2->setFont(QFont("Times",16));
    cb2->setIcon(QIcon(":/images/js.png"));
    cb2->setIconSize(QSize(40,40));

    connect(cb2,SIGNAL(stateChanged(int)),this,SLOT(changeCheckBox()));

    cb3 = new QCheckBox();
    cb3->setText("Go");
    cb3->setFont(QFont("Times",16));
    cb3->setIcon(QIcon(":/images/go.png"));
    cb3->setIconSize(QSize(40,40));

    connect(cb3,SIGNAL(stateChanged(int)),this,SLOT(changeCheckBox()));

    // Label
    label = new QLabel("HELLO FROM ADARSH");
    label->setFont(QFont("Times",20));

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(label);

    // adding to hboxLayout

    hbox->addWidget(cb1);
    hbox->addWidget(cb2);
    hbox->addWidget(cb3);

    vbox->addLayout(hbox);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeCheckBox()
{
    QString val = "";

    if(cb1->isChecked()){
        val = cb1->text();
    }
    if(cb2->isChecked()){
        val = cb2->text();
    }
    if(cb3->isChecked()){
        val = cb3->text();
    }
    label->setText("Seleceted Checkbox is :"+ val );
}
