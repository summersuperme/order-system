#include "sign_in.h"
#include "ui_sign_in.h"
#include <QMessageBox>
#include<QDebug>

Sign_in::Sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_in)
{
    ui->setupUi(this);
    Reg = new Registers();
    key = new Keyboard();
    connect(Reg,SIGNAL(sign(QString,QString)),
            this,SLOT(slotSign(QString,QString)));
    connect(key,SIGNAL(sendM(QString)),
            this,SLOT(recvM(QString)));
    this->setMinimumSize(1024, 600);

    //设置QLabel的伙伴 ----- 通过alt+快捷键快速定位到lab的伙伴
    ui->label_username->setBuddy(ui->lineEdit_username);
    ui->label_password->setBuddy(ui->lineEdit_password);

    ui->lineEdit_username->setText("superme");
    ui->lineEdit_password->setText("xia123");

    //设置行编辑器的显示方式
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

}

Sign_in::~Sign_in()
{
    delete ui;
    delete Reg;
    delete lineEdit;
    delete key;
}
void Sign_in::on_sign_in_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString pwd = ui->lineEdit_password->text();
    if(username.isEmpty() || pwd.isEmpty())
        return;
    emit login(username,pwd);
    key->close();
}



void Sign_in::on_Register_clicked()
{
    this->close();
    Reg->show();
}

void Sign_in::on_unsign_in_clicked()
{
    Hotel h;
    h.show();
    h.exec();
}
void Sign_in::slotSign(QString username,QString passwd)
{
    emit sign_up(username,passwd);
}
void Sign_in::recvM(QString ch)
{
    if(ch == "back")
        lineEdit->backspace();
    else if(ch == "clean")
        lineEdit->clear();
    else if(ch == "close")
        key->close();
    else
        lineEdit->insert(ch);
}

void Sign_in::on_lineEdit_username_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    key->setGeometry(0,220,1100,1100);
    key->show();
}

void Sign_in::on_lineEdit_password_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    key->setGeometry(0,220,1100,1100);
    key->show();
}
