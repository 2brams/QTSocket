#include <QCoreApplication>
#include "sockettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketTest cTest;
    while (1) {
        cTest.Connect();
    }


    return a.exec();
}
