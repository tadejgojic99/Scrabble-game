#include "headers/scoreboard.h"

ScoreBoard::ScoreBoard()
{
    // inicijalizacija table
    Constants *l = new Constants();

    // polje u igri
    vector<vector<unsigned int>> field_temp {{l->WORDx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx3},
                                        {l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY},
                                        {l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY},
                                        {l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY},
                                        {l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2},
                                        {l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY},
                                        {l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY},
                                        {l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY},
                                        {l->WORDx3,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->WORDx3},
                                        {l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY},
                                        {l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY},
                                        {l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY},
                                        {l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2},
                                        {l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY},
                                        {l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY},
                                        {l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY},
                                        {l->WORDx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx3}};
    // slova na tabli
    vector<vector<QChar>> letters_temp;
    for (int y = 0; y < l->LEN_Y; y++)
    {
        vector<QChar> temp;
        for (int x = 0; x < l->LEN_X; x++)
        {
            temp.push_back(' ');    // koristimo blanko karakter jer jos uvek nema postavljenih slova
        }
        letters_temp.push_back(temp);
    }

    // matrica unetih slova
    vector<vector<bool>> tmpNewLetters;
    for (int y = 0; y < l->LEN_Y; y++)
    {
        vector<bool> tmp_2;
        for (int x = 0; x < l->LEN_X; x++)
        {
            tmp_2.push_back(false);    // koristimo False jer jos uvek nema unetih slova
        }
        tmpNewLetters.push_back(tmp_2);
    }

    // proveravati
    field = field_temp;
    letters = letters_temp;
    newLetters = tmpNewLetters;
    wildcard = tmpNewLetters;      // kao i za nova slova, vrednosti za dzokere ce na pocetku biti postavljene na False
}

int ScoreBoard::calculateScore()
{
    Constants *l = new Constants();
    int score = 0;

    // Za svako polje proveravamo da li rec pocinje od njega i ukoliko da proveravamo da li treba da racunamo rezultat
    for (int y = 0; y < l->LEN_Y; y++)
    {
        for (int x = 0; x < l->LEN_X; x++)
        {
            // provera da li je polje prazno
            if (letters[y][x] != ' ')
            {
                // provera da li je ovo pocetak horizontalne reci
                if ((firstLeft(x,y) == 1) && ((firstRight(x,y) > 1) || (firstRight(x,y) == 0)))
                {
                    QString WORD;
                    int right;
                    bool existsWildCard = false;
                    bool test = false;          // ako je test true onda ce se izracunati rezultat za datu rec
                    if (firstRight(x,y) == 0)   // ako je prvo desno jednako 0, onda se rec zavrsava na kraju table
                        right = l->LEN_X - x;
                    else
                        right = firstRight(x,y);
                    // hvatamo novu rec+
                    for (int i = x; i < x + right; i++)
                    {
                        WORD.push_back(letters[y][i]);
                        // ako je ubaceno novo slovo, onda je formirana nova rec
                        if (newLetters[y][i])
                        {
                            test = true;    // potrebno je ponovo izracunati rezultat
                        }
                        if (wildcard[y][i])    // provera da li su za formiranje reci korisceni dzokeri
                            existsWildCard = true;
                    }
                    // na kraju izracunati rezultat
                    if (test)
                    {
                        // kontrolne varijable koje koristimo za mnozenje rezultata
                        bool ind2xWord = false;
                        bool ind3xWord = false;
                        // prolazimo kroz sva slova reci
                        for (int i = 0; i < WORD.length(); i++)
                        {
                            // provera da li postoji neko specijalno polje
                            switch ((field[y][x+i])) {
                            case Constants::EMPTY:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'];
                                break;
                            case Constants::WORDx2:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'];
                                ind2xWord = true;
                                break;
                            case Constants::WORDx3:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'];
                                ind3xWord = true;
                                break;
                            case Constants::LETTERx2:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'] *2;
                                break;
                            case Constants::LETTERx3:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'] *3;
                                break;
                            }
                        }
                        // na kraju pomznozimo rezultat reci
                        if (ind2xWord)
                            score = score *2;
                        if (ind3xWord)
                            score = score *3;
                        // ukoliko je duzina reci 6 onda se dodaje bonus od 10 poena
                        if (WORD.length() == 6)
                            score += 10;
                        // ukoliko je duzina reci 7 onda se dodaje bonus od 30 poena
                        if (WORD.length() == 7)
                            score += 30;
                        // ukoliko je duzina reci 8 onda se dodaje bonus od 50 poena
                        if (WORD.length() == 8)
                            score += 50;
                        // ukoliko je sastavljena rec SCRABBLE dobija se bonus od 100 poena
                        if (WORD == "SCRABBLE")
                            score += 100;
                        if (!existsWildCard)     // ako nisu korisceni dzokeri
                            score += 10;
                    }
                }
                // provera da li je ovo pocetak vertikalne reci
                if  ((firstUp(x,y) == 1) && ((firstDown(x,y) > 1) || (firstDown(x,y) == 0)))
                {
                    QString WORD;
                    int down;
                    bool existsWildCard = false;
                    bool test = false;      // ako je test true onda ce se izracunati rezultat za datu rec
                    if (firstDown(x,y) == 0)
                        down = l->LEN_Y - y;
                    else
                        down = firstDown(x,y);
                    // hvatamo novu rec
                    for (int i = y; i < y + down; i++)
                    {
                        WORD.push_back(letters[i][x]);
                        // ako je ubaceno novo slovo, onda je formirana nova rec
                        if (newLetters[i][x])
                        {
                            test = true;    // ponovo racunamo rezultat
                        }
                        if (wildcard[i][x])    // proverava da li su za formiranje reci korisceni dzokeri
                            existsWildCard = true;

                    }
                    // na kraju izracunati rezultat
                    if (test)
                    {
                        bool ind2xWord = false;
                        bool ind3xWord = false;
                        // prolazimo kroz sva slova reci
                        for (int i = 0; i < WORD.length(); i++)
                        {
                            // provera da li postoji neko posebno polje
                            switch ((field[y+i][x])) {
                            case l->EMPTY:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'];
                                break;
                            case l->WORDx2:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'];
                                ind2xWord = true;
                                break;
                            case l->WORDx3:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'];
                                ind3xWord = true;
                                break;
                            case l->LETTERx2:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'] *2;
                                break;
                            case l->LETTERx3:
                                score += l->LETTER_SCORES[0 + WORD.at(i).unicode()-'A'] *3;
                                break;
                            }
                        }
                        // na kraju pomnozimo rezultat reci
                        if (ind2xWord)
                            score = score *2;
                        if (ind3xWord)
                            score = score *3;
                        // ukoliko je duzina reci 6 onda se dodaje bonus od 10 poena
                        if (WORD.length() == 6)
                            score += 10;
                        // ukoliko je duzina reci 7 onda se dodaje bonus od 30 poena
                        if (WORD.length() == 7)
                            score += 30;
                        // ukoliko je duzina reci 8 onda se dodaje bonus od 50 poena
                        if (WORD.length() == 8)
                            score += 50;
                        // ukoliko je sastavljena rec SCRABBLE dobija se bonus od 100 poena
                        if (WORD == "SCRABBLE")
                            score += 100;
                        if (!existsWildCard)     // ako nisu korisceni dzokeri
                            score += 10;
                    }
                }
            }
        }
    }

    return score;
}



vector<vector<unsigned int> > ScoreBoard::getField() const
{
    return field;
}

void ScoreBoard::setField(const vector<vector<unsigned int> > &value)
{
    field = value;
}

vector<vector<QChar> > ScoreBoard::getLetters() const
{
    return letters;
}

void ScoreBoard::setLetters(const vector<vector<QChar> > &value)
{
    letters = value;
}

vector<vector<bool> > ScoreBoard::getNewLetters() const
{
    return newLetters;
}

void ScoreBoard::setNewLetters(const vector<vector<bool> > &value)
{
    newLetters = value;
}

vector<vector<bool> > ScoreBoard::getWildcard() const
{
    return wildcard;
}

void ScoreBoard::setWildcard(const vector<vector<bool> > &value)
{
    wildcard = value;
}

bool ScoreBoard::isNear(int x, int y)
{
    bool temp = false;
    Constants *l = new Constants();

    if (x != 0)
        if (letters[x-1][y] != ' ' )
            temp = true;
    if (x != l->LEN_X-1)
        if (letters[x+1][y] != ' ')
            temp = true;
    if (y != 0)
        if (letters[x][y-1] != ' ')
            temp = true;
    if (y != l->LEN_Y-1)
        if (letters[x][y+1] != ' ')
            temp = true;

    return temp;
}

int ScoreBoard::firstUp(int x, int y)
{
    int distance = 0;
    int temp = 0;
    bool fine = false;

    temp = y - 1;
    while (!fine)
    {
        // provera da nismo izasli van table
        if (temp != -1)
        {
            // provera da li je naredno polje prazno
            if (letters[temp][x] == ' ')
            {
                fine = true;
            }
            else    // inace proveravamo naredno
                temp--;
        }
        else    // ako smo na kraju zavrsavamo
            fine = true;
    }

    if (temp != -1)
        distance = y - temp;    //  racunamo rastojanje oduzimanje kordinate pocetnog polja od trenutnog polja
    else
        distance = 0;   // ovo znaci da nema praznih polja

    return distance;
}

int ScoreBoard::firstRight(int x, int y)
{
    int distance = 0;
    int temp = 0;
    bool fine = false;
    Constants *l = new Constants();

    temp = x + 1;
    while (!fine)
    {
        // provera da nismo izasli van table
        if (temp != l->LEN_X)
        {
            // provera da li je naredno polje prazno
            if (letters[y][temp] == ' ')
            {
                fine = true;
            }
            else    // inace proveravamo sledece
                temp++;
        }
        else    // ako smo na kraju, zavrsavamo
            fine = true;
    }

    if (temp != l->LEN_X)
        distance = temp - x;    // racunamo rastojanje oduzimanje kordinate pocetnog polja od trenutnog polja
    else
        distance = 0;   // ovo znaci da nema praznih polja

    return distance;
}

int ScoreBoard::firstDown(int x, int y)
{
    int distance = 0;
    int temp = 0;
    bool fine = false;
    Constants *l = new Constants();

    temp = y + 1;
    while (!fine)
    {
        // provera da nismo izasli van table
        if (temp != l->LEN_Y)
        {
            // provera da li je naredno polje prazno
            if (letters[temp][x] == ' ')
            {
                fine = true;
            }
            else    // inace proveravamo sledece
                temp++;
        }
        else    // ako smo na kraju, zavrsavamo
            fine = true;
    }

    if (temp != l->LEN_Y)
        distance = temp - y; // racunamo rastojanje oduzimanje kordinate pocetnog polja od trenutnog polja
    else
        distance = 0;   // ovo znaci da nema praznih polja

    return distance;
}

int ScoreBoard::firstLeft(int x, int y)
{
    int distance = 0;
    int temp = 0;
    bool fine = false;

    temp = x - 1;
    while (!fine)
    {
        // provera da nismo izasli van table
        if (temp != -1)
        {
            // provera da li je naredno polje prazno
            if (letters[y][temp] == ' ')
            {
                fine = true;
            }
            else    // inace proveravamo sledece
                temp--;
        }
        else    // ako smo na kraju, zavrsavamo
            fine = true;
    }

    if (temp != -1)
        distance = x - temp;    // racunamo rastojanje oduzimanje kordinate pocetnog polja od trenutnog polja
    else
        distance = 0;   // ovo znaci da nema praznih polja

    return distance;
}

void ScoreBoard::setNewLetterValue(bool value, int x, int y)
{
    newLetters[y][x] = value;
}

void ScoreBoard::setLetterValue(QChar value, int x, int y)
{
    letters[y][x] = value;
}

void ScoreBoard::setWildcard(bool value, int x, int y)
{
    wildcard[y][x] = value;
}
