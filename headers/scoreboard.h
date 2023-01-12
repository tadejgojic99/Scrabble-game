#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QString>
#include <QChar>
#include <vector>
#include <QMessageBox>
#include "dictionary.h"
#include "constants.h"

using namespace::std;

class ScoreBoard
{
public:
    ScoreBoard();

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
    vector<vector<unsigned int>> getField() const;
    void setField(const vector<vector<unsigned int>> &value);

    vector<vector<QChar>> getLetters() const;
    void setLetters(const vector<vector<QChar>> &value);

    vector<vector<bool> > getNewLetters() const;
    void setNewLetters(const vector<vector<bool> > &value);

    vector<vector<bool> > getWildcard() const;
    void setWildcard(const vector<vector<bool> > &value);

private:
    vector<vector<unsigned int>> field;     // tabla sa kutijicama
    vector<vector<QChar>> letters;          // slova na poljima
    vector<vector<bool>> newLetters;        // indikator slova koja su postavljena u trenutnoj rundi
    vector<vector<bool>> wildcard;             // indikator slova koja su dzoker
};


#endif // SCOREBOARD_H
