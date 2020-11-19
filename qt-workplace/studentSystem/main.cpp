

#include "mainwidget.h"
#include <QApplication>
int main(int argc,char** argv)
{
    //应用程序对象
    QApplication a(argc,argv);

    MainWidget mainWidget;

    mainWidget.show();

    return a.exec();
}
