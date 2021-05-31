#ifndef HOTEL_H
#define HOTEL_H

#include <QDialog>
#include <QScrollBar>
#include <QMouseEvent>
#include <QPoint>
#include <QMessageBox>
#include <QDebug>
extern "C"{
#include <sys/ioctl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#define GPIO_ON   _IOW('G', 0, int)
#define GPIO_OFF  _IOW('G', 1, int)
#define BRIEF_LINES 4
//char *ds18b20_path = {"/dev/ds18b20"};
//char *brief[BRIEF_LINES] = {
//        " =================================",
//        "| .........DS18B20......               |",
//        "| ............1s..................          |",
//        " ================================="};
float get_temp();
//void draw_string(char *buf[], unsigned int line);

}

namespace Ui {
class Hotel;
}

class Hotel : public QDialog
{
    Q_OBJECT
    
public:
    explicit Hotel(QWidget *parent = 0);
    ~Hotel();
     void price_sum();
     void set_mess();      //设置当前用户的用户名 余额 积分
//     float get_temp();
//     void draw_string(char *buf[], unsigned int line);

signals:
     void closeH(QString balance);
     void pay(QString username,QString price);
private slots:
    void on_checkBox_1_stateChanged();              //勾选框1
    void on_checkBox_2_stateChanged();              //勾选框2
    void on_checkBox_3_stateChanged();              //勾选框3
    void on_checkBox_4_stateChanged();              //勾选框4
    void on_checkBox_5_stateChanged();              //勾选框5
    void on_checkBox_6_stateChanged();              //勾选框6
    void on_checkBox_7_stateChanged();              //勾选框7
    void on_checkBox_8_stateChanged();              //勾选框8
    void on_checkBox_9_stateChanged();              //勾选框9

    void on_spinBox_1_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
    void on_spinBox_3_valueChanged(int arg1);
    void on_spinBox_4_valueChanged(int arg1);
    void on_spinBox_5_valueChanged(int arg1);
    void on_spinBox_6_valueChanged(int arg1);
    void on_spinBox_7_valueChanged(int arg1);
    void on_spinBox_8_valueChanged(int arg1);
    void on_spinBox_9_valueChanged(int arg1);
    void mouseMoveEvent(QMouseEvent *e);
    void on_pushButton_3_clicked();

    void on_pushButton_place_clicked();

private:
    Ui::Hotel *ui;
    int price1,num1 ;                        //菜样1单价,数量
    int price2 ,num2;                        //菜样2单价,数量
    int price3 ,num3 ;                        //菜样3单价,数量
    int price4 ,num4 ;                        //菜样4单价,数量
    int price5 ,num5 ;                        //菜样5单价,数量
    int price6 ,num6 ;                        //菜样6单价,数量
    int price7 ,num7 ;                        //菜样7单价,数量
    int price8 ,num8 ;                        //菜样8单价,数量
    int price9 ,num9 ;                        //菜样9单价,数量
public:
    QString balance;
    int offset;
    QPoint point;
    QString username;
};

#endif // HOTEL_H
