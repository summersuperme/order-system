#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QTcpServer>
#include <QByteArray>
#include <QString>

#include "database.h"

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(qintptr socketDescriptor,QObject *parent = 0);
    ~mythread();
    void run();
    bool login();
    void sign();
    void ExitThread();
    bool Str2QString(const char *str);
    char *getconsum_info();
    void logstep();
    void menustep();
    void recharge();
    void repwd();
    void bindCID();
    void pay();
signals:

public slots:

private:
    qintptr m_socketDescriptor;
    QTcpSocket *tcpSocket;
    DataBase *db;
    QString username;
    QString passwd;
};

#endif // MYTHREAD_H
