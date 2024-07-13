#include "widget.h"
#include "ui_widget.h"
#include<QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(500,100);

    QVBoxLayout *vBox= new QVBoxLayout(this);
    QHBoxLayout *hBox = new QHBoxLayout();

    qlcd =  new QLCDNumber(this);
    qlcd -> setStyleSheet("background-color:red");

    label = new QLabel();
    label->setText("Guess Who's Back");
    label->setFont(QFont("Times",18));

    QPushButton *btn = new QPushButton(this);
    btn->setFont(QFont("Times",18));
    btn->setText("Random Generator");

    // combobox
    comboBox = new QComboBox();
    comboBox->setFont(QFont("Times",18));
    comboBox->addItem("Slim Shady");
    comboBox->addItem("John Cena");
    comboBox->addItem("Taylor Swift");
    comboBox->addItem("Shreya Goshal");
    comboBox->addItem("❤️");


    //conn
    connect(btn, SIGNAL(clicked()), this, SLOT(RandGenerator()));
    connect(comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(ComboChanged()));

    hBox->addWidget(label);
    hBox->addWidget(comboBox);

    vBox->addWidget(qlcd);
    vBox->addWidget(btn);
    vBox->addWidget(label);
    vBox->addLayout(hBox);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::RandGenerator()
{
    int randomNumber = rand() % 1001;
    qlcd->display(randomNumber);
}

void Widget::ComboChanged()
{
    QString itemName = comboBox->currentText();
    label->setText("Guess Who's Back : " + itemName);
}
