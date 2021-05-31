#include "registers.h"
#include "ui_registers.h"

Registers::Registers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registers)
{
    ui->setupUi(this);
    key = new Keyboard();
    this->setMinimumSize(1024,600);
    ui->label_username->setBuddy(ui->lineEdit_username);
    ui->label_password->setBuddy(ui->lineEdit_password);

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_username->setFocus();
    connect(key,SIGNAL(sendM(QString)),
            this,SLOT(recvM(QString)));

}

Registers::~Registers()
{
    delete ui;
    delete lineEdit;
    delete key;
}


void Registers::on_pushButton_clicked()
{
    key->close();
    if(ui->lineEdit_username->text().isEmpty() || ui->lineEdit_password->text().isEmpty())
    {
        //弹出消息对话框
        QMessageBox box;
        box.setText("用户名或密码不能为空!");
        box.setStyleSheet("font: 10pt;");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
    }
    else
    {
        QString name = ui->lineEdit_username->text();
        QString psw = ui->lineEdit_password->text();
        if(ui->lineEdit->text()!=ui->lineEdit_password->text())
        {
            QMessageBox box;
            box.setStyleSheet("font: 10pt;");
            box.setText("两次输入密码不一致!");
            box.setIcon(QMessageBox::Warning);
            box.setWindowTitle("提示");
            box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
            box.exec();
            return;
        }

        else{
            emit sign(name,psw);
        }
    }
    this->close();


}

void Registers::on_pushButton_2_clicked()
{
    key->close();
    emit closeRe();
}
void Registers::recvM(QString ch)
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

void Registers::on_lineEdit_username_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    key->setGeometry(0,220,1100,1100);
    key->show();
}

void Registers::on_lineEdit_password_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    key->setGeometry(0,220,1100,1100);
    key->show();
}

void Registers::on_lineEdit_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    key->setGeometry(0,220,1100,1100);
    key->show();
}
