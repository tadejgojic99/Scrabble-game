#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <QVector>
#include <QMessageBox>
#include "dictionary.h"
#include "constants.h"


using namespace::std;

class Board
{

public:
    Board();

    int calculateScore();

    bool isNear(int x, int y);
    int firstUp(int x, int y);
    int firstRight(int x, int y);
    int firstDown(int x, int y);
    int firstLeft(int x, int y);


    void setNewLetterValue(bool value, int x, int y);
    void setLetterValue(char value,int x, int y);
    void setWildcard(bool value, int x, int y);


    QVector<QVector<unsigned int>> getField() const;
    void setField(const QVector<QVector<unsigned int>> &value);

    QVector<QVector<char>> getLetters() const;
    void setLetters(const QVector<QVector<char>> &value);

    QVector<QVector<bool> > getNewLetters() const;
    void setNewLetters(const QVector<QVector<bool> > &value);

    QVector<QVector<bool> > getWildcard() const;
    void setWildcard(const QVector<QVector<bool> > &value);

    void addNewLetter(const QVector<QVector<bool> > &value);
    void clearNewLetters();
    void resetBoard();

    char getLetterValue(int x, int y);

    bool isEmpty();

private:
    QVector<QVector<unsigned int>> field;
    QVector<QVector<char>> letters;
    QVector<QVector<bool>> newLetters;
    QVector<QVector<bool>> wildcard;
};


#endif // BOARD_H
