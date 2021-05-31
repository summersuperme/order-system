#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>

namespace Ui {
class Keyboard;
}

class Keyboard : public QDialog
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = 0);
    ~Keyboard();
signals:
    void sendM(QString ch);

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_BACK_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_W_clicked();

    void on_pushButton_E_clicked();

    void on_pushButton_R_clicked();

    void on_pushButton_T_clicked();

    void on_pushButton_Y_clicked();

    void on_pushButton_U_clicked();

    void on_pushButton_I_clicked();

    void on_pushButton_O_clicked();

    void on_pushButton_P_clicked();

    void on_pushButton_A_clicked();

    void on_pushButton_S_clicked();

    void on_pushButton_D_clicked();

    void on_pushButton_F_clicked();

    void on_pushButton_G_clicked();

    void on_pushButton_H_clicked();

    void on_pushButton_J_clicked();

    void on_pushButton_K_clicked();

    void on_pushButton_L_clicked();

    void on_pushButton_Z_clicked();

    void on_pushButton_X_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_V_clicked();

    void on_pushButton_B_clicked();

    void on_pushButton_N_clicked();

    void on_pushButton_M_clicked();

    void on_pushButton_CLEAR_clicked();

    void on_pushButton_clicked();

    void on_pushButton_CHANGE_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::Keyboard *ui;
    int flag;
};

#endif // KEYBOARD_H
