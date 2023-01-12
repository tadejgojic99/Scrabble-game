#ifndef PREFIXTREE_H
#define PREFIXTREE_H

#include <string>
#include <QString>

class PrefixTree
{

public:
    PrefixTree();
    ~PrefixTree();   // ubacicu i destruktor, buduci da pravimo nove objekte ove klase kao naslednike, doslo bi do curenja memorije

    static const int NUM_OF_CHARS = 26;
    static const int PREFIX = 1;
    static const int WORD = 2;
    static const int NONE = 0;

    void insert(const QString &word);   // dodajemo rec u strukturu

    // vraca:
    // PrefixTree::WORD, ukoliko je rec u strukturi
    // PrefixTree::PREFIX, ako se rec sadrzi u jednoj ili vise reci u strukturi
    // PrefixTree::NONE, inace
    int find(const QString &word);
    bool noSuccessor(const QString &word);   // proverava da li se rec ne sadrzi u strukturi, prateci prefiksno stablo

private:
    bool endOfWord;   // indikator kraja reci


    // Ovo je jako vazno, za svako slovo cemo u sustini praviti novo prefiksno stablo
    PrefixTree* successor[NUM_OF_CHARS];    // uopste ne prihvata bez '*', pretpostavljam da ni ne moze bez, staticka promenljiva ne bi bila pogodna

    void insert(const QString &word, int cur);

    int find(const QString &word, int cur);


};

#endif // PREFIXTREE_H

