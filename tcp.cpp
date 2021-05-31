#include "tcp.h"
#include "ui_tcp.h"

tcp::tcp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tcp)
{
    this->setMinimumSize(1024,600);
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    //Sign_in log;
    log = new Sign_in();
    mes = new User_mess();
    key = new Keyboard(this);
    connect(log,SIGNAL(login(QString,QString)),
            this,SLOT(slotLogin(QString,QString)));
    connect(log,SIGNAL(sign_up(QString,QString)),
            this,SLOT(slotregister(QString,QString)));
    connect(mes->Rep,SIGNAL(repwd(QString,QString)),
            this,SLOT(slotRepwd(QString,QString)));
    connect(mes,SIGNAL(User_exit()),
            this,SLOT(slotUser_exit()));
    connect(mes->bind,SIGNAL(bindID(QString,QString)),
            this,SLOT(slotBindCID(QString,QString)));
    connect(mes->rcg,SIGNAL(recharge(QString,QString)),
            this,SLOT(slotRecharge(QString,QString)));
    connect(log->Reg,SIGNAL(closeRe()),
            this,SLOT(slotcloseRe()));
    connect(mes->H,SIGNAL(closeH(QString)),
            this,SLOT(slotcloseH(QString)));
    connect(mes->H,SIGNAL(pay(QString,QString)),
            this,SLOT(slotpay(QString,QString)));
    connect(key,SIGNAL(sendM(QString)),
            this,SLOT(recvM(QString)));
    ui->lineEdit_ip->setText("192.168.7.103");
    ui->lineEdit_port->setText("8888");
}

tcp::~tcp()
{
    delete ui;
    delete socket;
    delete log;
    delete Per;
    delete mes;
    delete key;
    delete lineEdit;
}

void tcp::on_pushButton_clicked()
{
    //1、创建套接字
    socket = new QTcpSocket;
    //2、填写服务器ip地址、端口号
    QString ip = ui->lineEdit_ip->text();
    int port   = ui->lineEdit_port->text().toInt();
    //3、建立连接（连接到服务器）
    //    socket->connectToHost(ip, port);
    socket->connectToHost(ip, port);

    //当建立连接成功， QTcpSocket 触发 connected 信号，表示连接服务器成功
    connect(socket, SIGNAL(connected()), this, SLOT(slotConnected()));
    //阻塞等待，网络中数据就立即返回；如果设定时间到了，网络没有数据也会立即返回
    //    socket->waitForReadyRead(10000);
    //    qDebug() << "recv: " << socket->readAll();

    //当网络中一有可读数据，就立即触发 readyRead信号
    //connect(socket, &QTcpSocket::readyRead, this, &QDialog::dataRecv);
    key->close();
}

void tcp::on_pushButton_2_clicked()
{
    this->close();
    key->close();
    log->show();
    log->exec();
}
void tcp::slotConnected()
{
    ui->textEdit->append("网络连接成功");
    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setEnabled(false);
}
void tcp::slotLogin(QString username,QString passwd)
{
    QString str;
    char buf[100] = {0};
    str = "log," + username + "," + passwd;
    socket->write(str.toUtf8());
    if(socket->waitForReadyRead())
    {
        socket->read(buf,50);
    }
    if(!qstrncmp(buf,"YES",3))
    {
        name = username;
        readmes(QString::fromUtf8(buf));
        log->close();
        mes->show();
    }
    else {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("账号或密码不正确！！");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        return;
    }
}
void tcp::slotregister(QString username,QString passwd)
{
    QString str;
    char buf[20];
    str = "sign," + username + "," + passwd;
    socket->write(str.toUtf8());
    if(socket->waitForReadyRead())
    {
        socket->read(buf,20);
    }
    if(!qstrncmp(buf,"YES",3))
    {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("注册成功，请登录!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        log->show();
    }
    else {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("用户已存在!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        log->Reg->show();
        return;
    }

}
void tcp::readmes(QString message)
{
    Per = new Person;
    message.remove("YES");
    mes->setname(name);
    if(!message.isEmpty())
    {
        QStringList Qlist = message.split(";");
        Per->username = Qlist.at(0);
        Per->CID = Qlist.at(1);
        Per->balance = Qlist.at(2);
        Per->integral = Qlist.at(3);
        mes->setInfo(Per);
    }
    mes->show();

}
void tcp::slotRepwd(QString name,QString passwd)
{
    QString str;
    char buf[20];
    str = "repwd," + name + "," + passwd;
    socket->write(str.toUtf8());
    if(socket->waitForReadyRead())
    {
        socket->read(buf,20);
    }
    if(!qstrncmp(buf,"YES",3))
    {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("密码修改成功!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();

        socket->write("quit",4);
        mes->cleantext();
        mes->close();
        mes->Rep->close();
        log->show();
    }
    else {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("密码修改失败!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        return;
    }
}

void tcp::slotUser_exit()
{
    socket->write("quit",4);
    mes->close();
    log->show();
}

void tcp::slotBindCID(QString username,QString passwd)
{
    QString str;
    char buf[20];
    str = "bind," + username + "," + passwd;
    socket->write(str.toUtf8());
    //qDebug()<<str;
    if(socket->waitForReadyRead())
    {
        socket->read(buf,20);
    }
    if(!qstrncmp(buf,"YES",3))
    {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("银行卡绑定成功!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        socket->write("quit",4);
        mes->cleantext();
        mes->close();
        mes->bind->close();
        log->show();
    }
    else {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("银行卡绑定失败!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        return;
    }
}
void tcp::slotRecharge(QString username,QString balance)
{
    QString str;
    char buf[100] = {0};
    str = "recharge," + username + "," + balance;
    socket->write(str.toUtf8());
    if(socket->waitForReadyRead())
    {
        socket->read(buf,100);
    }
    if(!qstrncmp(buf,"YES",3))
    {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("充值成功!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        readmes(QString::fromUtf8(buf));
        mes->rcg->close();
    }
    else {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("充值失败!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        return;
    }
}

void tcp::slotcloseRe()
{
    log->Reg->close();
    log->show();
}

void tcp::slotcloseH(QString balance)
{

    mes->H->close();
    mes->balance = balance;
    mes->setbalance();
    mes->show();
}

void tcp::slotpay(QString username,QString price)
{
    QString str;
    char buf[100] = {0};
    str = "pay," + username + "," + price;
    socket->write(str.toUtf8());
    str.clear();
    if(socket->waitForReadyRead())
    {
        socket->read(buf,100);
    }
    if(!qstrncmp(buf,"YES",3))
    {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("支付成功!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        QString str = QString::fromUtf8(buf);
        QStringList Qlist;
        Qlist = str.split(";");
        mes->H->balance = Qlist.at(2);
        mes->H->set_mess();
    }
    else {
        QMessageBox box;
        box.setStyleSheet("font: 10pt;");
        box.setText("支付失败!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        return;
    }
}

void tcp::recvM(QString ch)
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


void tcp::on_lineEdit_ip_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    key->setGeometry(0,220,1100,1100);
    key->show();
}

void tcp::on_lineEdit_port_selectionChanged()
{
    QObject *obj;
    obj = sender();
    if(obj->metaObject()->className() == QStringLiteral("QLineEdit"))
        lineEdit = qobject_cast<QLineEdit*>(obj);
    key->setGeometry(0,220,1100,1100);
    key->show();
}
