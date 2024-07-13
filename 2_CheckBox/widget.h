#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>

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
    QCheckBox *cb1;
    QCheckBox *cb2;
    QCheckBox *cb3;
public slots:
    void changeCheckBox();
};
#endif // WIDGET_H
