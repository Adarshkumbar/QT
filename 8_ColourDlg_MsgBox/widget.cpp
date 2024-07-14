#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *vBox = new QVBoxLayout(this);
    QHBoxLayout *hBox = new QHBoxLayout();

    label = new QLabel(this);
    label->setText("adarsh");

    edit = new QTextEdit();
    edit->setFont(QFont("Times",18));

    QPushButton *btn = new QPushButton();
    btn->setText("Change Color");
    btn->setFont(QFont("Times",18));

    QPushButton *btn2 = new QPushButton();
    btn2->setText("Open Font");
    btn2->setFont(QFont("Times",18));

    QPushButton *btnA = new QPushButton();
    btnA->setText("Warning");
    btnA->setFont(QFont("Times",17));

    QPushButton *btnB = new QPushButton();
    btnB->setText("Information");
    btnB->setFont(QFont("Times",17));

    QPushButton *btnC = new QPushButton();
    btnC->setText("About");
    btnC->setFont(QFont("Times",17));

    // Conn
    connect(btn, SIGNAL(clicked()), this, SLOT(changeColor()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(changeText()));

    // conn message boxes
    connect(btnA,SIGNAL(clicked()), this, SLOT(warnMsg()));
    connect(btnB,SIGNAL(clicked()), this, SLOT(infoMsg()));
    connect(btnC,SIGNAL(clicked()), this, SLOT(aboutMsg()));

    // VBOX
    vBox->addWidget(label);
    vBox->addWidget(edit);
    vBox->addWidget(btn);
    vBox->addWidget(btn2);

    hBox->addWidget(btnA);
    hBox->addWidget(btnB);
    hBox->addWidget(btnC);
    vBox->addLayout(hBox);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeColor()
{
    colorDialog = new QColorDialog();
    QColor color = colorDialog->getColor(Qt::yellow);
    edit->setTextColor(color);
}

void Widget::changeText()
{
    bool ok;
    QFont font = fontDialog->getFont(&ok,QFont("Helvetical[cronyx]",12),this);

    if(ok){
        edit->setFont(font);
    }
}

void Widget::warnMsg()
{
    QMessageBox::warning(this,"Warning","This is Warning");
}

void Widget::infoMsg()
{
    QMessageBox::information(this,"Information","This is Adarsh Kumbar");
}

void Widget::aboutMsg()
{
    QMessageBox::about(this,"About","Software Engineer @Esko");
}
