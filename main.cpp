#include "main_server.h"
#include <QApplication>
#include <QTcpServer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_server w;
    w.show();
    
    return a.exec();
}
