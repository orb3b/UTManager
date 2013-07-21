#include "View/MainView.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;
    w.show();
    
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    return a.exec();
}
