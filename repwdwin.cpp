#include "repwdwin.h"
#include "ui_repwdwin.h"

RepwdWin::RepwdWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RepwdWin)
{
    ui->setupUi(this);
    key = new Keyboard(this);
    lineEdit = new QLineEdit();
    connect(key,SIGNAL(sendM(QString)),
            this,SLOT(recvM(QString)));
}

RepwdWin::~RepwdWin()
{
    delete ui;
    delete key;
    delete lineEdit;
}

void RepwdWin::recvM(QString ch)
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

void RepwdWin::on_lineEdit_repwd_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    lineEdit->clear();
    key->setGeometry(0,220,1100,1100);
    key->show();
}

void RepwdWin::on_lineEdit_confirm_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    lineEdit->clear();
    key->setGeometry(0,220,1100,1100);
    key->show();
}

void RepwdWin::on_pushButton_OK_clicked()
{
    QMessageBox box;
    QString repwds;
    QString conpwd;
    repwds = ui->lineEdit_repwd->text();
    conpwd = ui->lineEdit_confirm->text();
    if(repwds.isEmpty() || conpwd.isEmpty())
    {
        box.setText("密码不能为空!");
        box.setStyleSheet("font: 10pt;");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        return;
    }
    else if(repwds != conpwd) {
        box.setText("两次密码不相同!");
        box.setStyleSheet("font: 10pt;");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        return;
    }
    else
    {
        emit repwd(username,repwds);
    }
}

void RepwdWin::on_pushButton_cancel_clicked()
{
    this->close();
}

 void RepwdWin::clean()
 {
     ui->lineEdit_confirm->clear();
     ui->lineEdit_repwd->clear();
 }
