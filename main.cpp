#include <QApplication>

#include "mainwindow.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication wallch(argc, argv);

    // set the application name & organization
    wallch.setOrganizationDomain("wallch.t35.me");
    wallch.setOrganizationName("Wallch");
    wallch.setApplicationName("Wallch");
    wallch.setApplicationVersion("2.1");

    MainWindow mainWindow;
    mainWindow.show();
    return wallch.exec();
}
