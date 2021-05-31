#include "bindid.h"
#include "ui_bindid.h"

BindID::BindID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BindID)
{
    ui->setupUi(this);
    key = new Keyboard(this);
    lineEdit = new QLineEdit();
    connect(key,SIGNAL(sendM(QString)),
            this,SLOT(recvM(QString)));
}

BindID::~BindID()
{
    delete ui;
    delete key;
    delete lineEdit;
}

void BindID::on_pushButton_2_clicked()
{
    this->close();
}
void BindID::recvM(QString ch)
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

void BindID::on_lineEdit_CID_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    lineEdit->clear();
    key->setGeometry(0,220,1100,1100);
    key->show();
}

void BindID::on_pushButton_clicked()
{
    QMessageBox box;
    QString CID;
    CID = ui->lineEdit_CID->text();
    if(CID.isEmpty())
    {
        box.setText("银行卡号不能为空!");
        box.setStyleSheet("font: 10pt;");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        return;
    }
    else
    {
        emit bindID(username,CID);
    }
}
void BindID::clean()
{
    ui->lineEdit_CID->clear();
}
