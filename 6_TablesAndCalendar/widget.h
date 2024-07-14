#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCalendarWidget>
#include <QLabel>

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
    QCalendarWidget *calendar;
    QLabel *label;
    QLabel *label2;

public slots:
    void DateSelected();
};
#endif // WIDGET_H
