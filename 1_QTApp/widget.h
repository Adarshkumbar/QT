#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
//Radiobtn
#include<QRadioButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QLabel *label;
    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;
public slots:
    void changeText();
};
#endif // WIDGET_H
