#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QChar>

class Card
{

public:
    Card();

    // getter i setter
    QChar getLetter() const;
    void setLetter(const QChar &value);

private:
    QChar letter;   // neka za sada ostane samo slovo kao atribut
};

#endif // CARD_H
