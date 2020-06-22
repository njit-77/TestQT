#include "mainwindow.h"
#pragma comment(lib, "Exercise7.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* hehe = new MainWindow();
    hehe->show();

    return a.exec();
}
