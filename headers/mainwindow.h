#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <iostream>
#include "headers/player.h"
#include "headers/board.h"
#include "headers/custombutton_box.h"
#include "headers/custombutton_card.h"
#include "headers/wildcard_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool getIsFirstLetter() const;
    void setIsFirstLetter(bool value);
    bool getIsHorizontal() const;
    void setIsHorizontal(bool value);
    int getPrevious_x() const;
    void setPrevious_x(int value);
    int getPrevious_y() const;
    void setPrevious_y(int value);

    char getWildCardLetter() const;
    void setWildCardLetter(const char &value);

public slots:
    void createBoard(Board myBoard);
    void receiveBoard(Board board);
    void receivePlayer(Player myPlayer);
    void receiveEnd(Player winningPlayer);
    void on_repeatTurn_pushButton_clicked();
    void on_endTurn_pushButton_clicked();
    void on_suggestion_pushButton_clicked();
    void receiveClickedButton();
    void receiveLetter(char letter);

signals:
    void sendRepeatFirstTurn();
    void sendRepeatTurn();
    void sendEndTurn(Board board);
    void sendRequestSuggestion();
    void sendUpdate(Board myBoard, std::string cards);

private:
    Ui::MainWindow *ui;
    bool isHorizontal;
    bool isFirstLetter;
    bool isFirstTurn;
    int previous_x;
    int previous_y;
    char wildcardLetter;
    Wildcard_Dialog w;
    //Board b;
    void setCardImage(CustomButton_Card *button, std::string imagePath);
    void setBoxImage(CustomButton_Box *button, std::string imagePath);

    // vracaju udaljenost do prve slobodne kutijice gore/desno/dole/levo; ukoliko vrati 0, nema  praznih kutijica
    int firstUp(int x, int y);
    int firstRight(int x, int y);
    int firstDown(int x, int y);
    int firstLeft(int x, int y);


};
#endif // MAINWINDOW_H
