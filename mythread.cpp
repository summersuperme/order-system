#include "mythread.h"

mythread::mythread(qintptr socketDescriptor,QObject *parent) :
    QThread(parent),m_socketDescriptor(socketDescriptor)
{
    db = new DataBase;
    db->createConnection();
    //db->createTable();
    //db->queryAll("user_info");
}

void mythread::run()
{
    tcpSocket = new QTcpSocket;
    if(!tcpSocket->setSocketDescriptor(m_socketDescriptor))
    {
        return;
    }
    logstep();

}
mythread::~mythread()
{
    delete tcpSocket;
    delete db;
}

bool mythread::login()
{
    QString myusername = "'" + username + "'";
    QString mypasswd = "'" + passwd + "'";
    QString str = "select * from user_info where username = " + myusername +" and passwd = " + mypasswd;
    if(username == "" || passwd == "")
    {
        qDebug()<<"not emply";
        return false;
    }
    bool ret = db->queryOne(str);
    if(ret)
    {
        tcpSocket->write("YES");
        return true;
    }
    else
    {
        tcpSocket->write("NO");
        return false;
    }
}

void mythread::sign()
{
    QString str;
    QString myusername = "'" + username + "'";
    QString mypasswd = "'" + passwd + "'";
    str = "select * from user_info where username = " + myusername;
    bool ret = db->queryOne(str);
    str.clear();
    if(ret)
    {
        return;
    }
    else
    {
        str = QString("insert into user_info values(%1, %2)").arg(myusername).arg(mypasswd);
        //qDebug()<<str;
        if(db->insert(str))
        {
            tcpSocket->write("YES");
        }
        else
        {
            tcpSocket->write("NO");
        }
    }

}
void mythread::ExitThread()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->waitForDisconnected();
}
bool mythread::Str2QString(const char *str)
{
    QString temp;
    temp = QString::fromUtf8(str);
    QStringList Qlist = temp.split(",");
    if(Qlist.length()<3)
    {
        tcpSocket->write("Not enough parameters");
        return false;
    }
    username = Qlist.at(1);
    passwd   = Qlist.at(2);
    /*qDebug()<<username;
    qDebug()<<passwd;*/
    return true;
}
char* mythread::getconsum_info()
{
    QString info;
    QString str = "select * from consum_info where username = '" + username + "'";
    info = db->queryinfo(str);
    if(info.isNull())
        return NULL;
    QByteArray qByteArray = info.toUtf8();
    char* sqlStr = qByteArray.data();
    return sqlStr;

}
void mythread::logstep()
{
    char str[50] = {0};
    char *strinfo = NULL;
    while (1) {
        if(tcpSocket->waitForReadyRead())
        {
            tcpSocket->read(str,50);
            //qDebug()<<str;
            if(!Str2QString(str))
                continue;
            if(!qstrncmp(str,"log",3))
            {
                if(login())
                {
                    memset(str,0,sizeof(str));
                    strinfo = getconsum_info();
                    if(strinfo)
                        tcpSocket->write(strinfo,strlen(strinfo)-1);
                    menustep();
                    break;
                }
                memset(str,0,sizeof(str));

            }
            if(!qstrncmp(str,"sign",4))
            {
                sign();
                memset(str,0,sizeof(str));
            }
            if(!qstrncmp(str,"quit",4))
            {
                ExitThread();
                break;
            }
        }
    }
}
void mythread::menustep()
{
    char str[50] = {0};
    while (1) {
        if(tcpSocket->waitForReadyRead())
        {
            tcpSocket->read(str,50);
            //qDebug()<<str;
            if(!qstrncmp(str,"repwd",5))
            {
                if(!Str2QString(str))
                    continue;
                repwd();
                memset(str,0,sizeof(str));
            }
            if(!qstrncmp(str,"bind",4))
            {
                if(!Str2QString(str))
                    continue;
                bindCID();
                memset(str,0,sizeof(str));
            }
            if(!qstrncmp(str,"recharge",8))
            {
                if(!Str2QString(str))
                    continue;
                recharge();
                memset(str,0,sizeof(str));
            }
            if(!qstrncmp(str,"pay",3))
            {
                if(!Str2QString(str))
                    continue;
                pay();
                memset(str,0,sizeof(str));
            }
            if(!qstrncmp(str,"quit",4))
                logstep();
        }
    }
}

void mythread::repwd()
{
    QString str;
    QString myusername = "'" + username + "'";
    QString mypasswd = "'" + passwd +"'";
    str = QString("update user_info set passwd = %1 where username = %2 ").arg(mypasswd).arg(myusername);
    bool ret = db->updateById(str);
    if(ret)
    {
        tcpSocket->write("YES",3);
    }
    else
    {
        tcpSocket->write("NO",3);
    }

}
void mythread::recharge()
{
    char *strinfo = NULL;
    QString str;
    QString balance;
    QString myusername = "'" + username + "'";
    float newbalance;
    str = QString("select balance from consum_info where username = %1").arg(myusername);
    balance = db->queryinfo(str);
    balance.remove(";");
    newbalance = balance.toFloat() + passwd.toFloat();
    str = QString("update consum_info set balance = %1 where username = %2 ").arg(newbalance).arg(myusername);
    bool ret = db->updateById(str);
    if(ret)
    {
        tcpSocket->write("YES",3);
        strinfo = getconsum_info();
        if(strinfo)
            tcpSocket->write(strinfo,strlen(strinfo)-1);
    }
    else
    {
        tcpSocket->write("NO",3);
    }
}
void mythread::bindCID()
{
    QString str;
    QString myusername = "'" + username + "'";
    QString mypasswd = "'" + passwd +"'";
    str = QString("insert into consum_info values(%1,%2,0.0,0) ").arg(myusername).arg(mypasswd);
    bool ret = db->insert(str);
    if(ret)
    {
        tcpSocket->write("YES",3);
    }
    else
    {
        tcpSocket->write("NO",3);
    }
}

void mythread::pay()
{
    char *strinfo = NULL;
    QString str;
    QString balance;
    QString myusername = "'" + username + "'";
    float newbalance;
    str = QString("select balance from consum_info where username = %1").arg(myusername);
    balance = db->queryinfo(str);
    balance.remove(";");
    newbalance = balance.toFloat() - passwd.toFloat();
    str = QString("update consum_info set balance = %1 where username = %2 ").arg(newbalance).arg(myusername);
    bool ret = db->updateById(str);
    if(ret)
    {
        tcpSocket->write("YES",3);
        strinfo = getconsum_info();
        if(strinfo)
            tcpSocket->write(strinfo,strlen(strinfo)-1);
    }
    else
    {
        tcpSocket->write("NO",3);
    }
}
