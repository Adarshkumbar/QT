#include "widget.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    std::cout<<"ADARSH IS ❤️";;
    return a.exec();
}
