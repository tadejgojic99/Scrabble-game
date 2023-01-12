#ifndef DECK_H
#define DECK_H

#include <string>
#include <algorithm>
//TODO:

class Deck
{

public:
    Deck();

    //getter i setter
    std::string getDeck() const;
    void setDeck(std::string &value);

    //ostale funkcije(doraditi, za sada mi ovo pada na pamet)
    void shuffleDeck();
    char getTopCard();
    bool isEmpty();
    void setEmpty(bool value);

private:
    std::string deck;
    bool empty;
};

#endif // DECK_H

