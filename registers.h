#ifndef REGISTERS_H
#define REGISTERS_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include "keyboard.h"
namespace Ui {
class Registers;
}

class Registers : public QDialog
{
    Q_OBJECT
    
public:
    explicit Registers(QWidget *parent = 0);
    ~Registers();

signals:
    void sign(QString name,QString psw);
    void closeRe();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_username_selectionChanged();

    void on_lineEdit_password_selectionChanged();

    void on_lineEdit_selectionChanged();
    void recvM(QString ch);
private:
    Ui::Registers *ui;
    QLineEdit *lineEdit;
    Keyboard *key;
};

#endif // REGISTERS_H
