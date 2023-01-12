#ifndef CARD_H
#define CARD_H

#include <string>
class Card
{

public:
    Card();

    char getLetter() const;
    void setLetter(const char &value);

private:
    char letter;
};

#endif // CARD_H
