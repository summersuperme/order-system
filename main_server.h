#ifndef MAIN_SERVER_H
#define MAIN_SERVER_H

#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include "myserver.h"

namespace Ui {
class main_server;
}

class main_server : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit main_server(QWidget *parent = 0);
    ~main_server();
private slots:

private:
    Ui::main_server *ui;
    myserver *my_server;
};

#endif // MAIN_SERVER_H
