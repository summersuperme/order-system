#include "hotel.h"
#include "ui_hotel.h"


bool ok;
Hotel::Hotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hotel)
{
    ui->setupUi(this);
    ui->pushButton_place->setEnabled(false);
    float temp = get_temp();
    QString temps = QString("%1").arg(temp);
    ui->label_temp->setText(temps);
    offset = 10;
    point.setX(0);
    point.setY(0);
    price1 = 0;num1 = 0;                        //菜样1单价,数量
    price2 = 0;num2 = 0;                        //菜样2单价,数量
    price3 = 0;num3 = 0;                        //菜样3单价,数量
    price4 = 0;num4 = 0;                        //菜样4单价,数量
    price5 = 0;num5 = 0;                        //菜样5单价,数量
    price6 = 0;num6 = 0;                        //菜样6单价,数量
    price7 = 0;num7 = 0;                        //菜样7单价,数量
    price8 = 0;num8 = 0;                        //菜样8单价,数量
    price9 = 0;num9 = 0;

    QPixmap pix1(":img/pic/t01.jpg");                      //设置图片路径
    pix1 = pix1.scaled(ui->label_30->size());           //设置图片的尺寸等于label窗口大小
    ui->label_30->setPixmap(pix1);                      //设置图片在对应窗口显示

    QPixmap pix2(":img/pic/t02.jpg");
    pix2 = pix2.scaled(ui->label_31->size());
    ui->label_31->setPixmap(pix2);

    QPixmap pix3(":img/pic/t03.jpg");
    pix3 = pix3.scaled(ui->label_32->size());
    ui->label_32->setPixmap(pix3);

    QPixmap pix4(":img/pic/t04.jpg");
    pix4 = pix4.scaled(ui->label_33->size());
    ui->label_33->setPixmap(pix4);

    QPixmap pix5(":img/pic/t05.jpg");
    pix5 = pix5.scaled(ui->label_34->size());
    ui->label_34->setPixmap(pix5);

    QPixmap pix6(":img/pic/t06.jpg");
    pix6 = pix6.scaled(ui->label_35->size());
    ui->label_35->setPixmap(pix6);

    QPixmap pix7(":img/pic/t07.jpg");
    pix7 = pix7.scaled(ui->label_36->size());
    ui->label_36->setPixmap(pix7);

    QPixmap pix8(":img/pic/t08.jpg");
    pix8 = pix8.scaled(ui->label_37->size());
    ui->label_37->setPixmap(pix8);

    QPixmap pix9(":img/pic/t09.jpg");
    pix9 = pix9.scaled(ui->label_38->size());
    ui->label_38->setPixmap(pix9);
}

Hotel::~Hotel()
{
    delete ui;
}

void Checked(Ui::Hotel *ui)                             //判断是否有菜样被勾选
{
    if(ui->checkBox_1->isChecked() == true ||
            ui->checkBox_2->isChecked() == true||
            ui->checkBox_3->isChecked() == true||
            ui->checkBox_4->isChecked() == true||
            ui->checkBox_5->isChecked() == true||
            ui->checkBox_6->isChecked() == true||
            ui->checkBox_7->isChecked() == true||
            ui->checkBox_8->isChecked() == true||
            ui->checkBox_9->isChecked() == true)
        ui->pushButton_place->setEnabled(true);

    else
        ui->pushButton_place->setEnabled(false);
}

void Hotel::price_sum()                                 //计算当前所选菜样的总价格并显示
{
    int sum = price1 * num1 + price2 * num2
            + price3 * num3 + price4 * num4
            + price5 * num5 + price6 * num6
            + price7 * num7 + price8 * num8
            + price9 * num9 ;

    QString price_sum = QString::number(sum);
    ui->label_price->setText(price_sum);
}
void Hotel::on_checkBox_1_stateChanged()                //菜样1的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_1->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_1->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_1->text();
        price1 = ui->lineEdit_1->text().toInt(&ok,10);  //菜样1的价格转int型整数
        num1   = ui->spinBox_1->text().toInt(&ok,10);   //菜样1的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_1->setEnabled(false);               //失能选框
        num1 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_2_stateChanged()                //菜样2的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_2->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_2->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_2->text();
        price2 = ui->lineEdit_2->text().toInt(&ok,10);  //菜样2的价格转int型整数
        num2   = ui->spinBox_2->text().toInt(&ok,10);   //菜样2的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_2->setEnabled(false);               //失能选框
        num2 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_3_stateChanged()                //菜样3的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_3->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_3->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_3->text();
        price3 = ui->lineEdit_3->text().toInt(&ok,10);  //菜样3的价格转int型整数
        num3   = ui->spinBox_3->text().toInt(&ok,10);   //菜样3的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_3->setEnabled(false);               //失能选框
        num3 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_4_stateChanged()                //菜样4的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_4->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_4->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_4->text();
        price4 = ui->lineEdit_4->text().toInt(&ok,10);  //菜样4的价格转int型整数
        num4   = ui->spinBox_4->text().toInt(&ok,10);   //菜样4的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_4->setEnabled(false);               //失能选框
        num4 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_5_stateChanged()                //菜样5的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_5->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_5->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_5->text();
        price5 = ui->lineEdit_5->text().toInt(&ok,10);  //菜样4的价格转int型整数
        num5   = ui->spinBox_5->text().toInt(&ok,10);   //菜样4的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_5->setEnabled(false);               //失能选框
        num5 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_6_stateChanged()                //菜样6的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_6->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_6->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_6->text();
        price6 = ui->lineEdit_6->text().toInt(&ok,10);  //菜样的价格转int型整数
        num6   = ui->spinBox_6->text().toInt(&ok,10);   //菜样6的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_6->setEnabled(false);               //失能选框
        num6 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_7_stateChanged()                //菜样7的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_7->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_7->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_7->text();
        price7 = ui->lineEdit_7->text().toInt(&ok,10);  //菜样7的价格转int型整数
        num7   = ui->spinBox_7->text().toInt(&ok,10);   //菜样7的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_7->setEnabled(false);               //失能选框
        num7 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_8_stateChanged()                //菜样8的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_8->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_8->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_8->text();
        price8 = ui->lineEdit_8->text().toInt(&ok,10);  //菜样8的价格转int型整数
        num8   = ui->spinBox_8->text().toInt(&ok,10);   //菜样8的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_8->setEnabled(false);               //失能选框
        num8 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::on_checkBox_9_stateChanged()                //菜样9的勾选框
{
    Checked(ui);                                        //判断是否有菜样被勾选
    if(ui->checkBox_9->isChecked()==true)               //判断是否被勾选
    {
        ui->spinBox_9->setEnabled(true);                //被勾选后使能选框
        //qDebug()<<ui->lineEdit_9->text();
        price9 = ui->lineEdit_9->text().toInt(&ok,10);  //菜样9的价格转int型整数
        num9   = ui->spinBox_9->text().toInt(&ok,10);   //菜样9的数量转int型整数
        price_sum();                                    //计算当前所选菜样的总价格并显示
    }

    else                                                //没有被勾选
    {
        ui->spinBox_9->setEnabled(false);               //失能选框
        num9 = 0;                                       //此菜样已选数量变为0
        price_sum();
    }
}

void Hotel::set_mess()
{
    ui->label_money->setText(balance);
}


void Hotel::on_spinBox_1_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_1->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num1   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_2_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_2->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num2   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_3_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_3->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num3   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_4_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_4->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num4   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_5_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_5->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num5   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_6_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_6->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num6   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_7_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_7->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num7   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_8_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_8->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num8   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::on_spinBox_9_valueChanged(int arg1)
{
    //price1 = ui->lineEdit_9->text().toInt(&ok,10);      //菜样1的价格转int型整数
    num9   = arg1;                                     //菜样1的数量转int型整数
    price_sum();
}
void Hotel::mouseMoveEvent(QMouseEvent *e)
{

    QScrollBar *QSB;
    QSB = ui->scrollArea->verticalScrollBar();
    int max = QSB->maximum();
    if(offset < 0)
    {
        offset = 0;
        return;
    }
    if(offset > max)
    {
        offset = max;
        return;
    }
    if(point.y() > e->pos().y())
    {
        offset += 10;
        if(offset <= max)
            QSB->setValue(offset);

        point.setY(e->pos().y());
    }
    else {
        offset -= 10;
        if(offset > 0)
            QSB->setValue(offset);
        point.setY(e->pos().y());
    }
}

void Hotel::on_pushButton_3_clicked()
{
    emit closeH(balance);
}

void Hotel::on_pushButton_place_clicked()
{
    float price;
    float money;
    price = ui->label_price->text().toFloat();
    money = ui->label_money->text().toFloat();
    if(money < price)
    {
        QMessageBox box;
        box.setGeometry(100,100,100,150);
        box.setStyleSheet("font: 10pt;");
        box.setText("余额不足,请充值!!");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("提示");
        box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        box.exec();
        return;
    }
    else {
        emit pay(username,ui->label_price->text());
    }
}
//void draw_string(char *buf[], unsigned int line)
//{
//        int i;
//        for (i = 0; i < line; i++) {
//                printf("%s\n", buf[i]);
//        }
//}

float get_temp()
{
    int fd = 0;
           unsigned int temp[2];
           float tempvalue;
           if ((fd = open("/dev/ds18b20", O_RDWR | O_NONBLOCK)) == -1) {
                   perror("open ds18b20 error\n");
                   exit(EXIT_FAILURE);
           }

          // draw_string(brief, BRIEF_LINES);
           while(1)
           {
                   temp[1] = ioctl(fd, GPIO_ON, temp);
                   if (temp[1] & 0x8000)
                   {
                       temp[1] = ~temp[1] + 1;
                       temp[1] &= 0xffff;
                       tempvalue = (float)(temp[1]) * 0.0625;
//                       printf("temp[1] =  - %d \r\n",temp[1]>>4);
//                       printf("temperature= - %.2f ..C\r\n",tempvalue);
//                       tempstr = QString("%1").arg(tempvalue);
//                       ui->label_temp->setText(tempstr);
                       return tempvalue;
                   }
                   else
                   {
                       temp[1]&=0xffff;
                       tempvalue=(float)(temp[1])*0.0625;
//                       printf("temp[1] =  %d \r\n",temp[1]>>4);
//                       printf("temperature= %.2f ..C\r\n",tempvalue);
                      return tempvalue;
                   }
                   sleep(1);
          }
}
