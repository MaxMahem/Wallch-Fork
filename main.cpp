#include "mainwindow.h"
#include <QtSingleApplication>

int main(int argc, char *argv[])
{
    QtSingleApplication wallch(argc, argv);

    QString commandLineArguments = wallch.arguments().join(" ");

    // set the application name & organization
    wallch.setOrganizationDomain("wallch.t35.me");
    wallch.setOrganizationName("Wallch");
    wallch.setApplicationName("Wallch");
    wallch.setApplicationVersion("2.1");

    if (wallch.sendMessage(commandLineArguments))
        return 0;

    MainWindow mainWindow;

    wallch.setActivationWindow(&mainWindow);

    mainWindow.show();

    return wallch.exec();
}
