#ifndef DECK_H
#define DECK_H

#include <string>
#include <algorithm>
#include <ctime>

class Deck
{

public:
    Deck();

    std::string getDeck() const;
    void setDeck(std::string &value);

    void shuffleDeck();
    char getTopCard();
    bool isEmpty();
    void setEmpty(bool value);

private:
    std::string deck;
    bool empty;
};

#endif // DECK_H
