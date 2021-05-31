#ifndef RECHARGEWIN_H
#define RECHARGEWIN_H

#include <QDialog>
#include <QDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include "keyboard.h"

namespace Ui {
class RechargeWin;
}

class RechargeWin : public QDialog
{
    Q_OBJECT
    
public:
    explicit RechargeWin(QWidget *parent = 0);
    ~RechargeWin();
    void clean();
signals:
    void recharge(QString name,QString balance);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void recvM(QString ch);
    void on_lineEdit_selectionChanged();

private:
    Ui::RechargeWin *ui;
    Keyboard *key;
    QLineEdit *lineEdit;
public:
    QString username;

};

#endif // RECHARGEWIN_H
