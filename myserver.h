#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>

#include "mythread.h"
#include "database.h"
class myserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit myserver(QObject *parent = 0);
    ~myserver();
    
signals:
    
public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
public:
    DataBase *db;
    
};

#endif // MYSERVER_H
