#include "user_mess.h"
#include "ui_user_mess.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QIODevice>
#include <QDebug>
#include<QString>
#include"sign_in.h"



User_mess::User_mess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_mess)
{
    ui->setupUi(this);
    this->setMaximumSize(1024,600);
    ui->label_name_2->setText(username);
    H = new Hotel();
    key = new Keyboard(this);
    Rep = new RepwdWin();
    bind = new BindID();
    rcg = new RechargeWin();
}

User_mess::~User_mess()
{
    delete ui;
    delete H;
    delete key;
    delete Rep;
    delete bind;
    delete rcg;
}



void User_mess::on_pushButton_exit_clicked()
{
    this->close();
    emit User_exit();
    cleantext();
}

void User_mess::on_pushButton_order_clicked()
{                         
    this->close();
    H->show();
    H->set_mess();
}
void User_mess::setInfo(Person *Per)
{
    ui->label_name_2->setText(username);
    ui->label_CID->setText(Per->CID);
    ui->label_balance->setText(Per->balance);
    ui->label_integral->setText(Per->integral);
    H->balance = Per->balance;
    H->username = username;
}

void User_mess::setbalance()
{
    ui->label_balance->setText(balance);
}


void User_mess::setname(QString name)
{
    username = name;
}

void User_mess::cleantext()
{
    ui->label_name_2->clear();
    ui->label_CID->clear();
    ui->label_balance->clear();
    ui->label_integral->clear();
}

void User_mess::on_pushButton_changepsw_clicked()
{
    Rep->username = username;
    Rep->clean();
    Rep->show();
}
void User_mess::on_Button_bind_clicked()
{
    bind->username = username;
    bind->clean();
    bind->show();

}
void User_mess::on_Button_Recharge_clicked()
{
    rcg->username = username;
    rcg->clean();
    rcg->show();
}

