#include "database.h"

DataBase::DataBase()
{
}
//建立一个数据库连接
bool DataBase::createConnection()
{
    //以后就可以用"sqlite1"与数据库进行连接了
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
    db.setDatabaseName("mydb");
    if( !db.open())
    {
        qDebug() << "无法建立数据库连接";
        return false;
    }
    else
        qDebug()<<"创建数据库成功!!";
    return true;
}

//创建数据库表
bool DataBase::createTable()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    QString str1 = "create table consum_info(username varchar primary key,CardID varchar,balance float,integral int)";
    QString str = "create table user_info(username varchar primary key,passwd varchar)";
    //QString str = "drop table consum_info";
    query.exec(str1);
    bool success = query.exec(str);
    if(success)
    {
        qDebug() << QObject::tr("数据库表创建成功！");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("数据库表已经存在！");
        return false;
    }
}

//向数据库中插入记录
bool DataBase::insert(QString str)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    QByteArray qByteArray = str.toUtf8();
    char* sqlStr = qByteArray.data();
    bool success=query.exec(sqlStr);
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
        return false;
    }
    return true;
}
//查询所有信息
bool DataBase::queryAll(QString tablename)
{
    QString sqlstr;
    sqlstr = "select * from " + tablename;
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec(sqlstr);
    QSqlRecord rec = query.record();
    while(query.next())
    {
        for(int index=0;index<rec.count();index++)
            qDebug() << query.value(index).toString();
    }
    return true;
}
//查询关键字
bool DataBase::queryOne(QString str)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1");
    QSqlQuery query(db);
    QByteArray qByteArray = str.toUtf8();
    char* sqlStr = qByteArray.data();
    if(!query.exec(sqlStr))
    {
        qDebug()<<"查询失败!!";
        return false;
    }
    if(query.next())
    {
        //qDebug()<<"user is exist!!";
        return true;
    }
    else
    {
        //qDebug()<<"not exist!!";
        return false;
    }

}
QString DataBase::queryinfo(QString str)
{
    QString info;
    QSqlDatabase db = QSqlDatabase::database("sqlite1");
    QSqlQuery query(db);
    QByteArray qByteArray = str.toUtf8();
    char* sqlStr = qByteArray.data();
    if(!query.exec(sqlStr))
    {
        qDebug()<<"查询失败!!";
        return NULL;
    }
    QSqlRecord rec = query.record();
    while(query.next())
    {
        for(int index=0;index<rec.count();index++)
        {
            info += query.value(index).toString();
            info += ";";
        }
    }
    //info.remove(";").end();
    return info;
}

//根据ID删除记录
bool DataBase::deleteBykey(QString username,QString tabname)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("delete from %1 where username = %2").arg(tabname).arg(username));
    //query.exec("delete from user_info");
    //query.exec("delete from consum_info");
    if(!query.exec())
    {
        qDebug() << "删除记录失败！";
        return false;
    }
    return true;
}

//根据ID更新记录
bool DataBase::updateById(QString str)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    QByteArray qByteArray = str.toUtf8();
    char* sqlStr = qByteArray.data();
    //str = "update consum_info set CardID = '122203612',balance = 75.6, integral = 400 where username = '1'";


    bool success=query.exec(sqlStr);
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
    }
    return true;
}

//排序
bool DataBase::sortById()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success=query.exec("select * from automobil order by id desc");
    if(success)
    {
        qDebug() << QObject::tr("排序成功");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("排序失败！");
        return false;
    }
}
