#include "headers/playersnumber_dialog.h"
#include "ui_playersnumber_dialog.h"

playersNumber_Dialog::playersNumber_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playersNumber_Dialog)
{
    ui->setupUi(this);


    QPixmap backgroundDialog(":/resources/images/6880AF.png");
    backgroundDialog = backgroundDialog.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette paletteDialog;
    paletteDialog.setBrush(QPalette::Window, backgroundDialog);
    this->setPalette(paletteDialog);

    QPixmap backgroundButton(":/resources/images/white.jpeg");
    backgroundButton = backgroundButton.scaled(ui->button2Players->size(), Qt::IgnoreAspectRatio);
    QPalette palette_button;
    palette_button.setBrush(QPalette::Button, backgroundButton);
    ui->button2Players->setFlat(true);
    ui->button2Players->setAutoFillBackground(true);
    ui->button2Players->setPalette(palette_button);

    ui->button3Players->setFlat(true);
    ui->button3Players->setAutoFillBackground(true);
    ui->button3Players->setPalette(palette_button);

    ui->button4Players->setFlat(true);
    ui->button4Players->setAutoFillBackground(true);
    ui->button4Players->setPalette(palette_button);
}

playersNumber_Dialog::~playersNumber_Dialog()
{
    delete ui;
}

void playersNumber_Dialog::on_button2Players_clicked()
{
    sendNumberOfPlayers(2);
    this->close();
}

void playersNumber_Dialog::on_button3Players_clicked()
{
    sendNumberOfPlayers(3);
    this->close();
}

void playersNumber_Dialog::on_button4Players_clicked()
{
    sendNumberOfPlayers(4);
    this->close();
}
