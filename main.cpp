#include "mainwindow.h"
#include <QApplication>
#include <QDBusConnection>
#include <QDebug>
#include <QDBusError>

#include "mainwindowadapter.h"
//#include <com_deepin_dbus_demo.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QDBusConnection connection = QDBusConnection::sessionBus();

    if(!connection.registerService("com.deepin.dbus.demo")){
        qDebug() << "Error:" << connection.lastError().message() << endl;
        exit(-1);
    }

    connection.registerObject("/com/deepin/dbus/demo", &w);

    DemoAdaptor adapter(&w);

    return a.exec();
}
