#include "headers/card.h"

Card::Card()
{
    // Ovo u sustini treba da predstavlja polje na koje se stavlja sama karta
    // Neka ostane prazan konstruktor, treba smisliti kako kartu vizuelno prikazati(vrednost karte moze da se menja, pa nije potrebno unapred fiksirati)
}

char Card::getLetter() const {
    return letter;
}

void Card::setLetter(const char &value) {
    letter = value;
}
