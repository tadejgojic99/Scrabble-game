#ifndef WILDCARD_DIALOG_H
#define WILDCARD_DIALOG_H

#include <QWidget>
#include <QDialog>
namespace Ui {
class Wildcard_Dialog;
}

class Wildcard_Dialog :  public QDialog
{
    Q_OBJECT

public:
    explicit Wildcard_Dialog(QWidget *parent = nullptr);
    ~Wildcard_Dialog();

private:
    Ui::Wildcard_Dialog *ui;

signals:
    void sendLetter(char letter);

private slots:
    void on_pushButton_A_clicked();
    void on_pushButton_B_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_D_clicked();
    void on_pushButton_E_clicked();
    void on_pushButton_F_clicked();
    void on_pushButton_G_clicked();
    void on_pushButton_H_clicked();
    void on_pushButton_I_clicked();
    void on_pushButton_J_clicked();
    void on_pushButton_K_clicked();
    void on_pushButton_L_clicked();
    void on_pushButton_M_clicked();
    void on_pushButton_N_clicked();
    void on_pushButton_O_clicked();
    void on_pushButton_P_clicked();
    void on_pushButton_Q_clicked();
    void on_pushButton_R_clicked();
    void on_pushButton_S_clicked();
    void on_pushButton_T_clicked();
    void on_pushButton_U_clicked();
    void on_pushButton_V_clicked();
    void on_pushButton_W_clicked();
    void on_pushButton_X_clicked();
    void on_pushButton_Y_clicked();
    void on_pushButton_Z_clicked();
};

#endif // WILDCARD_DIALOG_H
