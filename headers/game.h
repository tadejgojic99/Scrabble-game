#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include "headers/deck.h"
#include "headers/player.h"
#include "headers/constants.h"
#include "headers/dictionary.h"
#include "headers/board.h"
#include <unordered_map>

class Game : public QObject // da bi signali i slotovi mogli da se povezu, mora da nasledjuje klasu QObject
{
    Q_OBJECT

public:
    explicit Game(QObject *parent = 0);

    void start();
    void nextPlayer();
    void manageCards();
    void calculateSuggestion();
    bool validation(Board tempBoard, bool inform);
    int getNumberOfPlayers() const;
    void setNumberOfPlayers(int &value);

    Board getMyBoard() const;
    void setMyBoard(const Board &value);
    Deck getDeck() const;
    void setDeck(Deck &value);

    QVector<Player> getPlayers() const;
    void setPlayers(QVector<Player> &value);

    void victory();
    void constructWords(std::unordered_map<char, int> &choice, std::string &curWord, QVector<std::string > &words);
    void resetBoard();
signals:
    void createBoard(Board myBoard);
    void sendBoard(Board myBoard);
    void sendPlayer(Player player);
    void sendEnd(Player winningPlayer);

public slots:
    void receiveNumberOfPlayers(int number);
    void receiveRepeatTurn();
    void receiveRepeatFirstTurn();
    void receiveUpdate(Board tempBoard, std::string cards);
    void receiveRequestSuggestion();
    void receiveEndTurn(Board tempBoard);

private:
    QVector<Player> players;
    Deck deck;
    int numberOfPlayers;
    int currentPlayer;
    Dictionary myDictionary = Dictionary("../10-igra-scrabble/resources/dictionary/dictionary.txt");
    Board myBoard;
    Constants l;
};

#endif // GAME_H
