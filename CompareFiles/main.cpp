#include "mainwindow.h"
#include <QApplication>
#include <QResource>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QResource::registerResource(QApplication::applicationDirPath()+
                                QDir::separator()+"resources"+
                                QDir::separator()+"comparefiles.rcc");
    QResource::registerResource(QApplication::applicationDirPath()+
                                QDir::separator()+"resources"+
                                QDir::separator()+"widgetsplugin.rcc");

    QDir pluginDir(QApplication::applicationDirPath());
    if (pluginDir.cd("plugins"))
        QApplication::addLibraryPath(pluginDir.absolutePath());

    MainWindow w;
    w.show();

    return a.exec();
}
