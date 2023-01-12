#ifndef PLAYERSNUMBER_DIALOG_H
#define PLAYERSNUMBER_DIALOG_H

#include <QDialog>

namespace Ui {
class playersNumber_Dialog;
}

class playersNumber_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit playersNumber_Dialog(QWidget *parent = nullptr);
    ~playersNumber_Dialog();

private:
    Ui::playersNumber_Dialog *ui;

signals:
    void sendNumberOfPlayers(int num);

private slots:
    void on_button2Players_clicked();
    void on_button3Players_clicked();
    void on_button4Players_clicked();
};

#endif // PLAYERSNUMBER_DIALOG_H
