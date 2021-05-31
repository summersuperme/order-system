#ifndef REPWDWIN_H
#define REPWDWIN_H

#include <QDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include "keyboard.h"

namespace Ui {
class RepwdWin;
}

class RepwdWin : public QDialog
{
    Q_OBJECT
    
public:
    explicit RepwdWin(QWidget *parent = 0);
    ~RepwdWin();
    void clean();
signals:
    void repwd(QString name,QString pasw);

private slots:
    void on_lineEdit_repwd_selectionChanged();


    void on_lineEdit_confirm_selectionChanged();

    void on_pushButton_OK_clicked();

    void on_pushButton_cancel_clicked();
    void recvM(QString ch);
private:
    Ui::RepwdWin *ui;
    Keyboard *key;
    QLineEdit *lineEdit;
public:
    QString username;
};

#endif // REPWDWIN_H
