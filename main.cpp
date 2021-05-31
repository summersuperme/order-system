#include <QApplication>
#include <QFontDatabase>
#include"tcp.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tcp w;
    w.setMinimumSize(1024, 600);
    w.show();
    int id = QFontDatabase::addApplicationFont("/usr/fonts/DroidSansFallback.ttf");
    QString msyh = QFontDatabase::applicationFontFamilies (id).at(0);
    QFont font(msyh,100);
    a.setFont(font);
    
    return a.exec();
}
