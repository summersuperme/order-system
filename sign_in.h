#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QTableWidgetItem>
#include <QLineEdit>
#include"registers.h"
#include"hotel.h"
#include"user_mess.h"
#include "keyboard.h"

namespace Ui {
class Sign_in;
}

class Sign_in : public QDialog
{
    Q_OBJECT
    
public:
    explicit Sign_in(QWidget *parent = 0);
    ~Sign_in();

signals:
    void login(QString username,QString passwd);
    void sign_up(QString username,QString passwd);
    void Repasswd(QString username,QString passwd);

private slots:
    void on_sign_in_clicked();

    void on_Register_clicked();

    void on_unsign_in_clicked();

    void slotSign(QString username,QString passwd);
    void on_lineEdit_username_selectionChanged();

    void on_lineEdit_password_selectionChanged();
    void recvM(QString ch);
private:
    Ui::Sign_in *ui;
    QLineEdit *lineEdit;
    Keyboard *key;
public:
    Registers *Reg;

};

#endif // SIGN_IN_H
