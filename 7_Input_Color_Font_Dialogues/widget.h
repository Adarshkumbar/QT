#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QInputDialog>
#include <QLineEdit>
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

    QInputDialog *inputDialogue;
    QLineEdit *lineEdit;
    QLabel *label;
};
#endif // WIDGET_H
