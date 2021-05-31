#include "rechargewin.h"
#include "ui_rechargewin.h"

RechargeWin::RechargeWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RechargeWin)
{
    ui->setupUi(this);
    key = new Keyboard(this);
    lineEdit = new QLineEdit();
    connect(key,SIGNAL(sendM(QString)),
            this,SLOT(recvM(QString)));
}

RechargeWin::~RechargeWin()
{
    delete ui;
    delete key;
    delete lineEdit;
}
void RechargeWin::recvM(QString ch)
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
void RechargeWin::on_pushButton_clicked()
{
    QMessageBox box;
    QString balance;
    balance = ui->lineEdit->text();
    if(balance.isEmpty())
    {
        box.setStyleSheet("font: 10pt;");
        box.setText("银行卡号不能为空!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        return;
    }
    else
    {
        emit recharge(username,balance);
    }
}

void RechargeWin::on_pushButton_2_clicked()
{
    this->close();
}

void RechargeWin::on_lineEdit_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    lineEdit->clear();
    key->setGeometry(0,220,1100,1100);
    key->show();
}
void RechargeWin::clean()
{
    ui->lineEdit->clear();
}
