#ifndef BOARD_H
#define BOARD_H

#include <QString>
#include <QChar>
#include <vector>
#include <QMessageBox>
#include "dictionary.h"
#include "constants.h"


using namespace::std;

class Board
{
public:
    Board();

    int calculateScore();                   // racunamo rezultat na osnovu slova iz prethodne runde

    bool isNear(int x, int y);              // vraca true ako je x_y kutijica blizu neke druge kutijice koja u sebi sadrzi neko slovo
    int firstUp(int x, int y);              // vraca udaljenost do prve slobodne kutijice iznad x_y kutijice
    int firstRight(int x, int y);           // vraca udaljenost do prve slobodne kutijice desno od x_y kutijice
    int firstDown(int x, int y);            // vraca udaljenost do prve slobodne kutijice ispod x_y kutijice
    int firstLeft(int x, int y);            // vraca udaljenost do prve slobodne kutijice levo od x_y kutijice
    // ako vrate 0, nema slobodnih kutijica

    void setNewLetterValue(bool value, int x, int y);        // dodeljuje vrednost x_y kutijici
    void setLetterValue(QChar value,int x, int y);           // dodeljuje vrednost x_y kutijici
    void setWildcard(bool value, int x, int y);            // dodeljuje vrednost x_y kutijici

    // getter-i i setter-i
    std::vector<std::vector<unsigned int>> getField() const;
    void setField(const std::vector<std::vector<unsigned int>> &value);

    std::vector<std::vector<QChar>> getLetters() const;
    void setLetters(const std::vector<std::vector<QChar>> &value);

    std::vector<std::vector<bool> > getNewLetters() const;
    void setNewLetters(const std::vector<std::vector<bool> > &value);

    std::vector<std::vector<bool> > getWildcard() const;
    void setWildcard(const std::vector<std::vector<bool> > &value);

private:
    std::vector<std::vector<unsigned int>> field;     // tabla sa kutijicama
    std::vector<std::vector<QChar>> letters;          // slova na poljima
    std::vector<std::vector<bool>> newLetters;        // indikator slova koja su postavljena u trenutnoj rundi
    std::vector<std::vector<bool>> wildcard;             // indikator slova koja su dzoker
};


#endif // BOARD_H
