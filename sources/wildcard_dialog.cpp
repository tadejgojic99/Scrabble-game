#include "headers/wildcard_dialog.h"
#include "ui_wildcard_dialog.h"

Wildcard_Dialog::Wildcard_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wildcard_Dialog)
{
    ui->setupUi(this);

    QPixmap background(":/resources/images/6880AF.png");
    QPalette paletteBackground;
    paletteBackground.setBrush(QPalette::Window, background);
    this->setPalette(paletteBackground);

    QPixmap button(":/resources/images/white.jpeg");
    button = button.scaled(ui->pushButton_A->size());  // skaliramo na dimenzije dugmeta
    QPalette paletteButton;
    paletteButton.setBrush(QPalette::Button, button);

    // na nasoj mrezi(sceni) podesavamo palete svih polja
    for (int x = 0; x < ui->gridLayout_Wildcard->count(); x++)
    {
        QPushButton *button = static_cast<QPushButton*>(ui->gridLayout_Wildcard->itemAt(x)->widget());
        button->setFlat(true);  // postavljamo da je dugme ravno(nije izdignuto)
        button->setAutoFillBackground(true);  // automatski se popunjava pozadina bojom definisanom u QPalette::Window
        button->setPalette(paletteButton);  // postavljamo gore definisanu paletu za polje
    }
}

Wildcard_Dialog::~Wildcard_Dialog()
{
    delete ui;
}

void Wildcard_Dialog::on_pushButton_A_clicked()
{
    sendLetter('A');
    this->close();
}

void Wildcard_Dialog::on_pushButton_B_clicked()
{
    sendLetter('B');
    this->close();
}

void Wildcard_Dialog::on_pushButton_C_clicked()
{
    sendLetter('C');
    this->close();
}

void Wildcard_Dialog::on_pushButton_D_clicked()
{
    sendLetter('D');
    this->close();
}

void Wildcard_Dialog::on_pushButton_E_clicked()
{
    sendLetter('E');
    this->close();
}

void Wildcard_Dialog::on_pushButton_F_clicked()
{
    sendLetter('F');
    this->close();
}

void Wildcard_Dialog::on_pushButton_G_clicked()
{
    sendLetter('G');
    this->close();
}

void Wildcard_Dialog::on_pushButton_H_clicked()
{
    sendLetter('H');
    this->close();
}

void Wildcard_Dialog::on_pushButton_I_clicked()
{
    sendLetter('I');
    this->close();
}

void Wildcard_Dialog::on_pushButton_J_clicked()
{
    sendLetter('J');
    this->close();
}

void Wildcard_Dialog::on_pushButton_K_clicked()
{
    sendLetter('K');
    this->close();
}

void Wildcard_Dialog::on_pushButton_L_clicked()
{
    sendLetter('L');
    this->close();
}

void Wildcard_Dialog::on_pushButton_M_clicked()
{
    sendLetter('M');
    this->close();
}

void Wildcard_Dialog::on_pushButton_N_clicked()
{
    sendLetter('N');
    this->close();
}

void Wildcard_Dialog::on_pushButton_O_clicked()
{
    sendLetter('O');
    this->close();
}

void Wildcard_Dialog::on_pushButton_P_clicked()
{
    sendLetter('P');
    this->close();
}

void Wildcard_Dialog::on_pushButton_Q_clicked()
{
    sendLetter('Q');
    this->close();
}

void Wildcard_Dialog::on_pushButton_R_clicked()
{
    sendLetter('R');
    this->close();
}

void Wildcard_Dialog::on_pushButton_S_clicked()
{
    sendLetter('S');
    this->close();
}

void Wildcard_Dialog::on_pushButton_T_clicked()
{
    sendLetter('T');
    this->close();
}

void Wildcard_Dialog::on_pushButton_U_clicked()
{
    sendLetter('U');
    this->close();
}

void Wildcard_Dialog::on_pushButton_V_clicked()
{
    sendLetter('V');
    this->close();
}

void Wildcard_Dialog::on_pushButton_W_clicked()
{
    sendLetter('W');
    this->close();
}

void Wildcard_Dialog::on_pushButton_X_clicked()
{
    sendLetter('X');
    this->close();
}

void Wildcard_Dialog::on_pushButton_Y_clicked()
{
    sendLetter('Y');
    this->close();
}

void Wildcard_Dialog::on_pushButton_Z_clicked()
{
    sendLetter('Z');
    this->close();
}
