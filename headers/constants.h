#ifndef CONSTANTS_H
#define CONSTANTS_H


class Constants
{
public:
    Constants();

    enum Values {
        // polja na tabli
        EMPTY = 0,
        WORDx2 = 1,
        WORDx3 = 2,
        LETTERx2 = 3,
        LETTERx3 = 4,
        CENTER = 5,
        // dimenzije tabele(standardna 15x15 polja)
        LEN_X = 15,
        LEN_Y = 15,

        HAND_SIZE = 8
    };
                               //  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
    const int LETTER_SCORES[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};  // vrednosti dobijene odavde: https://scrabble.hasbro.com/en-us/faq
};

#endif // CONSTANTS_H
