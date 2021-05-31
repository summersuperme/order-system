#ifndef DATABASE_H
#define DATABASE_H

#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QString>

class DataBase
{
public:
    DataBase();
public:
    bool createConnection();  //创建一个连接
    bool createTable();       //创建数据库表
    bool insert(QString usernema,QString passwd);
    bool insert(QString str);//插入数据
    bool queryAll(QString tablename);          //查询所有信息
    bool updateById(QString str);  //更新
    bool deleteBykey(QString tabname,QString username);  //删除
    bool sortById();          //排序
    bool queryOne(QString str);
    QString queryinfo(QString str);
};

#endif // DATABASE_H
