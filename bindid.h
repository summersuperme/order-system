#ifndef BINDID_H
#define BINDID_H

#include <QDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include "keyboard.h"

namespace Ui {
class BindID;
}

class BindID : public QDialog
{
    Q_OBJECT
    
public:
    explicit BindID(QWidget *parent = 0);
    ~BindID();
    void clean();
signals:
    void bindID(QString name,QString CID);
private slots:
    void on_pushButton_2_clicked();
    void recvM(QString ch);

    void on_lineEdit_CID_selectionChanged();

    void on_pushButton_clicked();

private:
    Ui::BindID *ui;
    Keyboard *key;
    QLineEdit *lineEdit;
public:
    QString username;
};

#endif // BINDID_H
