#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLCDNumber>

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
    QLCDNumber *lcd;

public slots:
    void showTime();
};
#endif // WIDGET_H
