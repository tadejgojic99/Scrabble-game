#include "board.h"
#include <iostream>

Board::Board()
{
    // inicijalizacija table
    Constants *l = new Constants();

    // polje u igri
    vector<vector<unsigned int>> field_temp {{l->WORDx3,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->WORDx3},
                                            {l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY},
                                            {l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY},
                                            {l->LETTERx2,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->LETTERx2},
                                            {l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY},
                                            {l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY},
                                            {l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY},
                                            {l->WORDx3,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->CENTER,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->WORDx3},
                                            {l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY},
                                            {l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY},
                                            {l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->EMPTY},
                                            {l->LETTERx2,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->LETTERx2},{l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY},
                                            {l->EMPTY,l->WORDx2,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx3,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx2,l->EMPTY},
                                            {l->WORDx3,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->EMPTY,l->WORDx3,l->EMPTY,l->EMPTY,l->EMPTY,l->LETTERx2,l->EMPTY,l->EMPTY,l->WORDx3}};

    // slova na tabli
    vector<vector<QChar>> letters_temp;
    for (int y = 0; y < l->LEN_Y; y++)
    {
        vector<QChar> temp;
        for (int x = 0; x < l->LEN_X; x++)
        {
            temp.push_back('#');    // koristimo blanko karakter jer jos uvek nema postavljenih slova
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


std::vector<std::vector<unsigned int> > Board::getField() const
{
    return field;
}

void Board::setField(const vector<vector<unsigned int> > &value)
{
    field = value;
}

vector<vector<QChar> > Board::getLetters() const
{
    return letters;
}

void Board::setLetters(const vector<vector<QChar> > &value)
{
    letters = value;
}

vector<vector<bool> > Board::getNewLetters() const
{
    return newLetters;
}

void Board::setNewLetters(const vector<vector<bool> > &value)
{
    newLetters = value;
}

vector<vector<bool> > Board::getWildcard() const
{
    return wildcard;
}

void Board::setWildcard(const vector<vector<bool> > &value)
{
    wildcard = value;
}


int Board::calculateScore()
{
    Constants *l = new Constants();
    int score = 0;

    // Za svako polje proveravamo da li rec pocinje od njega i ukoliko da proveravamo da li treba da racunamo rezultat
    for (int y = 0; y < l->LEN_Y; y++)
    {
        for (int x = 0; x < l->LEN_X; x++)
        {
            // provera da li je polje prazno
            if (letters[y][x] != '#')
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
//                        std::cout << WORD.length() << std:: endl;
                        for (int i = 0; i < WORD.length(); i++)
                        {
                            // provera da li postoji neko specijalno polje
                            switch ((field[y][x+i])) {
                                case Constants::EMPTY: {
                                        int tmp1 = WORD.toLower().at(i).unicode()-'a';
                                        score += l->LETTER_SCORES[0 + tmp1];
                                        break;
                                    }
                                case Constants::CENTER: {
                                        int tmp2 = WORD.toLower().at(i).unicode()-'a';
                                        score += l->LETTER_SCORES[0 + tmp2];
                                        break;
                                    }
                                case Constants::WORDx2: {
                                        int tmp3 = WORD.toLower().at(i).unicode()-'a';
                                        score += l->LETTER_SCORES[0 + tmp3];
                                        ind2xWord = true;
                                        break;
                                }
                                case Constants::WORDx3: {
                                        int tmp4 = WORD.toLower().at(i).unicode()-'a';;
                                        score += l->LETTER_SCORES[0 + tmp4];
                                        ind3xWord = true;
                                        break;
                                }
                                case Constants::LETTERx2: {
                                        int tmp5  = WORD.toLower().at(i).unicode()-'a';
                                        score += l->LETTER_SCORES[0 + tmp5] *2;
                                        break;
                                }
                                case Constants::LETTERx3: {
                                        int tmp6 =  WORD.toLower().at(i).unicode()-'a';
                                        score += l->LETTER_SCORES[0 + tmp6] *3;
                                        break;
                                }

                                default: {
                                    break;
                                }

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
                            case Constants::EMPTY:
                                score += l->LETTER_SCORES[0 + WORD.toLower().at(i).unicode()-'a'];
                                break;
                            case Constants::CENTER:
                                score += l->LETTER_SCORES[0 + WORD.toLower().at(i).unicode()-'a'];
                                break;
                            case Constants::WORDx2:
                                score += l->LETTER_SCORES[0 + WORD.toLower().at(i).unicode()-'a'];
                                ind2xWord = true;
                                break;
                            case Constants::WORDx3:
                                score += l->LETTER_SCORES[0 + WORD.toLower().at(i).unicode()-'a'];
                                ind3xWord = true;
                                break;
                            case Constants::LETTERx2:
                                score += l->LETTER_SCORES[0 + WORD.toLower().at(i).unicode()-'a'] *2;
                                break;
                            case Constants::LETTERx3:
                                score += l->LETTER_SCORES[0 + WORD.toLower().at(i).unicode()-'a'] *3;
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

int Board::firstUp(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = y - 1;
    while (!end)
    {
        if (tmp != -1)
        {
            if (letters[tmp][x] == '#')
            {
                end = true;
            }
            else
                tmp--;
        }
        else
            end = true;
    }

    if (tmp != -1)
        dist = y - tmp;
    else
        dist = 0;

    return dist;
}

int Board::firstRight(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = x + 1;
    while (!end)
    {
        // isti princip, proveravamo da li je van granica itd..
        if (tmp != Constants::LEN_X)
        {
            if (letters[y][tmp] == '#')
            {
                end = true;
            }
            else
                tmp++;
        }
        else
            end = true;
    }

    if (tmp != Constants::LEN_X)
        dist = tmp - x;
    else
        dist = 0;

    return dist;
}

int Board::firstDown(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = y + 1;
    while (!end)
    {
        if (tmp != Constants::LEN_Y)
        {
            if (letters[tmp][x] == '#')
            {
                end = true;
            }
            else
                tmp++;
        }
        else
            end = true;
    }

    if (tmp != Constants::LEN_Y)
        dist = tmp - y;
    else
        dist = 0;

    return dist;
}

int Board::firstLeft(int x, int y)
{
    int dist = 0;
    int tmp = 0;
    bool end = false;

    tmp = x - 1;
    while (!end)
    {
        if (tmp != -1)
        {
            if (letters[y][tmp] == '#')
            {
                end = true;
            }
            else
                tmp--;
        }
        else
            end = true;
    }

    if (tmp != -1)
        dist = x - tmp;
    else
        dist = 0;

    return dist;
}

void Board::setNewLetterValue(bool value, int x, int y)
{
    newLetters[y][x] = value;
}

void Board::setLetterValue(QChar value, int x, int y)
{
    letters[y][x] = value;
}

void Board::setWildcard(bool value, int x, int y)
{
    wildcard[y][x] = value;
}

bool Board::isNear(int x, int y){
    bool temp = false;

        if (x != 0)
            if (letters[x-1][y] != ' ' )
                temp = true;
        if (x != Constants::LEN_X-1)
            if (letters[x+1][y] != ' ')
                temp = true;
        if (y != 0)
            if (letters[x][y-1] != ' ')
                temp = true;
        if (y != Constants::LEN_Y-1)
            if (letters[x][y+1] != ' ')
                temp = true;

        return temp;
}
