
#include "Controller.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{   
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling,true);
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
//    a.setWindowIcon(QIcon(":/images/thelogo.png"));

    Controller c;
//    qDebug() << c.pLogin;
    return a.exec();
}
