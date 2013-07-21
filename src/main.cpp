#include "View/MainView.h"
#include <QApplication>
#include <QStyleFactory>
#include "Logger.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(Logger::messageHandler);
    QApplication a(argc, argv);

    MainView w;
    w.show();
    
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    return a.exec();
}
