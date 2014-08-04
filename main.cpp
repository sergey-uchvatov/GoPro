#include <QDebug>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;

    mainWindow.setFixedSize(400, 300);
    mainWindow.show();

    return app.exec();
}
