#ifndef USER_MESS_H
#define USER_MESS_H

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QTableWidgetItem>
#include <QInputDialog>

#include "hotel.h"
#include "keyboard.h"
#include "repwdwin.h"
#include "bindid.h"
#include "rechargewin.h"

struct Person{
    QString CID;
    QString username;
    QString balance;
    QString integral;
};

namespace Ui {
class User_mess;
}

class User_mess : public QDialog
{
    Q_OBJECT
    
public:
    explicit User_mess(QWidget *parent = 0);
    ~User_mess();

    void setInfo(Person *Per);
    void setname(QString name); //显示当前用户所有信息
    void cleantext();
    void setbalance();
signals:
    void User_exit();


    //extern QString NAME;
private slots:
    void on_pushButton_changepsw_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_order_clicked();

    void on_Button_bind_clicked();

    void on_Button_Recharge_clicked();

private:
    Ui::User_mess *ui;
    Keyboard *key;
    QString username; 
public:
    Hotel *H;
    RepwdWin *Rep;
    BindID *bind;
    RechargeWin *rcg;
    QString balance;
    QString integral;
};

#endif // USER_MESS_H
