#include "View/MainView.h"
#include <QApplication>
#include <QPlastiqueStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;
    w.show();
    
    QApplication::setStyle(new QPlastiqueStyle);

    return a.exec();
}
