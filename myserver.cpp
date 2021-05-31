#include "myserver.h"


myserver::myserver(QObject *parent) :
    QTcpServer(parent)
{
    /*db = new DataBase;
    db->createConnection();
    //db->createTable();
    db->deleteBykey("'1'","user_info");
    //QString str = "insert into consum_info values(1, 51010 ,65.3,300)";
    //db->insert(str);
    //db->updateById(1);
    db->queryAll("user_info");*/
    /*QString info = db->queryinfo("y");
    qDebug()<<info;*/
}

void myserver::incomingConnection(qintptr socketDescriptor)
{
    mythread* thread = new mythread(socketDescriptor, 0);
    thread->start();
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);
}

myserver::~myserver()
{
    delete db;
}
