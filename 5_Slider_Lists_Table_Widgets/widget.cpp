#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(600,200);

    QHBoxLayout *hBox = new QHBoxLayout();
    QVBoxLayout *vBox = new QVBoxLayout(this);

// SLIDER
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setTickInterval(5);
    slider->setMaximum(1);
    slider->setMaximum(100);

    QListWidget *listWidget = new QListWidget(this);
    listWidget->setFont(QFont("Times",18));

// listWidget->setStyleSheet("background-color:yellow");

    listWidget->insertItem(0,"C++");
    listWidget->insertItem(1,"JavaScript");
    listWidget->insertItem(2,"Java");
    listWidget->insertItem(3,"React");
    listWidget->insertItem(4,"NodeJs");

// TextEdit and Font Combo
    fontCombo = new QFontComboBox();
    textEdit = new QTextEdit();

    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(ChangeSlider()));
    connect(fontCombo,SIGNAL(currentFontChanged(QFont)),this,SLOT(ChangeFont()));

    label = new QLabel("SLIDER");
    label->setFont(QFont("Times",16));

    hBox->addWidget(label);
    hBox->addWidget(slider);

    vBox->addLayout(hBox);
    vBox->addWidget(listWidget);
    vBox->addWidget(fontCombo);
    vBox->addWidget(textEdit);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeSlider()
{
    int val = slider->value();
    label->setText(QString::number(val));
}

void Widget::ChangeFont()
{
    QFont myFont = QFont(fontCombo->itemText(fontCombo->currentIndex()));
    textEdit->setFont(myFont);
}
