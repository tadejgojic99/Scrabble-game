#ifndef PREFIXTREE_H
#define PREFIXTREE_H

#include <string>
#include <QVector>

class PrefixTree
{

public:
    PrefixTree();
    ~PrefixTree();

    static const int NUM_OF_CHARS = 26;
    static const int PREFIX = 1;
    static const int WORD = 2;
    static const int NONE = 0;

    bool endOfWord;


    PrefixTree* successor[NUM_OF_CHARS];


    void insert(const std::string &word);

    // vraca:
    // PrefixTree::WORD, ukoliko je rec u strukturi
    // PrefixTree::PREFIX, ako se rec sadrzi u jednoj ili vise reci u strukturi
    // PrefixTree::NONE, inace
    int find(const std::string &word);
    bool noSuccessor(const std::string &word);   // proverava da li se rec ne sadrzi u strukturi, prateci prefiksno stablo

private:

    void insert(const std::string &word, int cur);

    int find(const std::string &word, int cur);


};

#endif // PREFIXTREE_H

