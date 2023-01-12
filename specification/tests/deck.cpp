#include "deck.h"

Deck::Deck()
{
    empty = false;
    // sudeci po ovome: https://scrabble.hasbro.com/en-us/faq, ovo je raspodela karata po spilu svakog igraca
    deck = "AAAAAAAAABBCCDDDDEEEEEEEEEEEEFFGGGHHIIIIIIIIIJKLLLLMMNNNNNNOOOOOOOOPPQRRRRRRSSSSTTTTTTUUUUVVWWXYYZ**"; // '*' ce nam biti dzoker karta
}

std::string Deck::getDeck() const {
    return deck;
}

void Deck::setDeck(std::string &value) {
    deck = value;
}

void Deck::shuffleDeck() {
    //std::random_shuffle(deck.begin(), deck.end());  // nema potrebe da sam implementiram, ovo bi trebalo da dobro radi

    int n1,n2;
    char temp;
    srand (time(NULL));

    // iteriramo kroz karte
    for (int x = 0; x < static_cast<int>(deck.length()) * 2; x++)
    {
        // nasumicno biramo dva indeksa
        n1 = rand() % deck.length();
        n2 = rand() % deck.length();

        // vrsimo zamenu
        temp = deck[n1];
        deck[n1] = deck[n2];
        deck[n2] = temp;
    }
}

char Deck::getTopCard() {
//    char topCard = deck.at(0);
//    deck.remove(0, 1); // ima 6 mogucih, nama treba samo uklanjanje elementa na poziciji 0, uz to ide i broj elemenata pocevsi od te pozicije

//    return topCard;

    char first = deck.at(0);
    deck = deck.erase(0,1);
    if (deck.length() == 0)
        empty = true;
    return first;

    // necu da proveravam da li je spil prazan u ovoj funkciji, da ne bih morao da pravim dva return-a, kasnije ce se onemoguciti pozivanje ove funkcije kada je spil prazan
}

bool Deck::isEmpty() {
    return empty;
}

void Deck::setEmpty(bool value) {
    empty = value;
}

