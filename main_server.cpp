#include "main_server.h"
#include "ui_main_server.h"

main_server::main_server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_server)
{
    ui->setupUi(this);
    my_server = new myserver();
    my_server->setMaxPendingConnections(5);
    my_server->listen(QHostAddress::Any,8888);

}

main_server::~main_server()
{
    delete ui;
    delete my_server;
}

