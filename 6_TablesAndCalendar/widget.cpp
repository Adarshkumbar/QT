#include "widget.h"
#include "ui_widget.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(800,400);

    QVBoxLayout *vBox = new QVBoxLayout(this);

    label = new QLabel();
    label->setText("CALENDAR");
    label2 = new QLabel();
    label2->setText("Select");
    label2->setFont(QFont("Times",16));

    // TABLE WIDGET
    QTableWidget *table = new QTableWidget(this);
    table->setFont(QFont("Times",18));
    table->setStyleSheet("background-color:maroon");

    // Setting row and colmn count
    table->setColumnCount(3);
    table->setRowCount(3);

    QTableWidgetItem *email = new QTableWidgetItem("Email");
    QTableWidgetItem *name = new QTableWidgetItem("Name");

    QTableWidgetItem *adarsh = new QTableWidgetItem("Adarsh");
    QTableWidgetItem *myEmail = new QTableWidgetItem("adarshbkumbar1@gmail.com");

    table->setItem(0,0,name);
    table->setItem(0,1,email);
    table->setItem(1,0,adarsh);
    table->setItem(1,1,myEmail);

    // CALENDAR
    calendar = new QCalendarWidget();
    calendar->setGridVisible(true);

    vBox->addWidget(table);
    vBox->addWidget(label);
    vBox->addWidget(calendar);
    vBox->addWidget(label2);

    // connect
    connect(calendar,SIGNAL(selectionChanged()),this,SLOT(DateSelected()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::DateSelected()
{
    QString dateSelcted = calendar->selectedDate().toString();
    label2->setText("Date Selected :" + dateSelcted);
}
