#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Keyboard)
{

    ui->setupUi(this);
    flag = 0;
}

Keyboard::~Keyboard()
{
    delete ui;
}
void Keyboard::on_pushButton_CHANGE_clicked()
{
    if(flag == 0)
        flag = 1;
    else
        flag = 0;
}

void Keyboard::on_pushButton_1_clicked()
{
    emit sendM("1");
}

void Keyboard::on_pushButton_2_clicked()
{
    emit sendM("2");
}

void Keyboard::on_pushButton_3_clicked()
{
    emit sendM("3");
}

void Keyboard::on_pushButton_4_clicked()
{
    emit sendM("4");
}

void Keyboard::on_pushButton_5_clicked()
{
    emit sendM("5");
}

void Keyboard::on_pushButton_6_clicked()
{
    emit sendM("6");
}

void Keyboard::on_pushButton_7_clicked()
{
    emit sendM("7");
}

void Keyboard::on_pushButton_8_clicked()
{
    emit sendM("8");
}

void Keyboard::on_pushButton_9_clicked()
{
    emit sendM("9");
}

void Keyboard::on_pushButton_0_clicked()
{
    emit sendM("0");
}

void Keyboard::on_pushButton_BACK_clicked()
{
    emit sendM("back");
}
void Keyboard::on_pushButton_CLEAR_clicked()
{
    emit sendM("clean");
}

void Keyboard::on_pushButton_clicked()
{
    emit sendM(" ");
}

void Keyboard::on_pushButton_Q_clicked()
{
    if(flag == 0)
        emit sendM("q");
    else
        emit sendM("Q");
}

void Keyboard::on_pushButton_W_clicked()
{
    if(flag == 0)
        emit sendM("w");
    else
        emit sendM("W");
}

void Keyboard::on_pushButton_E_clicked()
{
    if(flag == 0)
        emit sendM("e");
    else
        emit sendM("E");
}

void Keyboard::on_pushButton_R_clicked()
{
    if(flag == 0)
        emit sendM("r");
    else
        emit sendM("R");
}

void Keyboard::on_pushButton_T_clicked()
{
    if(flag == 0)
        emit sendM("t");
    else
        emit sendM("T");
}

void Keyboard::on_pushButton_Y_clicked()
{
    if(flag == 0)
        emit sendM("y");
    else
        emit sendM("Y");
}

void Keyboard::on_pushButton_U_clicked()
{
    if(flag == 0)
        emit sendM("u");
    else
        emit sendM("U");
}

void Keyboard::on_pushButton_I_clicked()
{
    if(flag == 0)
        emit sendM("i");
    else
        emit sendM("I");
}

void Keyboard::on_pushButton_O_clicked()
{
    if(flag == 0)
        emit sendM("o");
    else
        emit sendM("O");
}

void Keyboard::on_pushButton_P_clicked()
{
    if(flag == 0)
        emit sendM("p");
    else
        emit sendM("P");
}

void Keyboard::on_pushButton_A_clicked()
{
    if(flag == 0)
        emit sendM("a");
    else
        emit sendM("A");
}

void Keyboard::on_pushButton_S_clicked()
{
    if(flag == 0)
        emit sendM("s");
    else
        emit sendM("S");
}

void Keyboard::on_pushButton_D_clicked()
{
    if(flag == 0)
        emit sendM("d");
    else
        emit sendM("D");
}

void Keyboard::on_pushButton_F_clicked()
{
    if(flag == 0)
        emit sendM("f");
    else
        emit sendM("F");
}

void Keyboard::on_pushButton_G_clicked()
{
    if(flag == 0)
        emit sendM("g");
    else
        emit sendM("G");
}

void Keyboard::on_pushButton_H_clicked()
{
    if(flag == 0)
        emit sendM("h");
    else
        emit sendM("H");
}

void Keyboard::on_pushButton_J_clicked()
{
    if(flag == 0)
        emit sendM("j");
    else
       emit sendM("J");
}

void Keyboard::on_pushButton_K_clicked()
{
    if(flag == 0)
        emit sendM("k");
    else
        emit sendM("K");
}

void Keyboard::on_pushButton_L_clicked()
{
    if(flag == 0)
        emit sendM("l");
    else
        emit sendM("L");
}

void Keyboard::on_pushButton_Z_clicked()
{
    if(flag == 0)
        emit sendM("z");
    else
        emit sendM("Z");
}

void Keyboard::on_pushButton_X_clicked()
{
    if(flag == 0)
        emit sendM("x");
    else
        emit sendM("X");
}

void Keyboard::on_pushButton_C_clicked()
{
    if(flag == 0)
        emit sendM("c");
    else
        emit sendM("C");
}

void Keyboard::on_pushButton_V_clicked()
{
    if(flag == 0)
        emit sendM("v");
    else
        emit sendM("V");
}

void Keyboard::on_pushButton_B_clicked()
{
    if(flag == 0)
        emit sendM("b");
    else
        emit sendM("B");
}

void Keyboard::on_pushButton_N_clicked()
{
    if(flag == 0)
        emit sendM("n");
    else
        emit sendM("N");
}

void Keyboard::on_pushButton_M_clicked()
{
    if(flag == 0)
        emit sendM("m");
    else
        emit sendM("M");
}



void Keyboard::on_pushButton_10_clicked()
{
    emit sendM("close");
}

void Keyboard::on_pushButton_11_clicked()
{
    emit sendM(".");
}
