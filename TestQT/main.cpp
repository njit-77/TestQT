#include "TestQT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestQT w;
    w.show();
    return a.exec();
}
