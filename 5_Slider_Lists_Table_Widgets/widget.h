#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QFontComboBox>
#include <QTextEdit>

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
    QSlider *slider;
    QLabel *label;
    QFontComboBox *fontCombo;
    QTextEdit *textEdit;

public slots :
    void ChangeSlider();
    void ChangeFont();
};
#endif // WIDGET_H
