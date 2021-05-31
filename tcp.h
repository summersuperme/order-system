#ifndef TCP_H
#define TCP_H

#include <QDialog>
#include <QTcpSocket>
#include <QDebug>
#include <string>
#include<QString>
#include<qstringlist.h>
#include <QLineEdit>
#include "sign_in.h"
#include "registers.h"
#include"user_mess.h"
#include "keyboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class tcp;
}
QT_END_NAMESPACE
class tcp : public QDialog
{
    Q_OBJECT

public:
    explicit tcp(QWidget *parent = 0);
    ~tcp();
    void readmes(QString message);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void slotConnected();

    void slotLogin(QString username,QString passwd);
    void slotregister(QString username,QString psw);
    void slotRepwd(QString username,QString passwd);
    void slotUser_exit();
    void slotBindCID(QString username,QString passwd);
    void slotRecharge(QString username,QString balance);
    void slotcloseRe();
    void slotcloseH(QString balance);
    void slotpay(QString username,QString price);
    void recvM(QString ch);
    void on_lineEdit_ip_selectionChanged();

    void on_lineEdit_port_selectionChanged();

signals:

private:
    Ui::tcp *ui;
    QTcpSocket *socket;
    Sign_in *log;
    User_mess *mes;
    Person *Per;
    QString name;
    Keyboard *key;
    QLineEdit *lineEdit;
};
#endif // TCP_H
