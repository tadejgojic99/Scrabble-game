#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QString>
#include <fstream>
#include "prefixtree.h"

class Dictionary
{

public:
    Dictionary(const char* file);   // konstruktor ce ucitavati recnik koji je u tekstualnom formatu, gde se u svakom redu nalazi tacno jedna rec

    // metodi za koje mislim da ce biti potrebni(naravno, mozda se ispostavi da je nedovoljno)
    bool containsWord(const QString &word);
    bool noSuccessor(const QString &word);

    // getter-i i setter-i i prilika da zapravo primenimo nesto iz KIAA
    PrefixTree getDictionary() const;        // bilo bi naivno da koristimo vektor stringova, kada su prefiksna stabla idealna za ovo
    void setDictionary(PrefixTree &value);   // nisam siguran ni da ce biti potrebno, ne vidim da se tokom igre ikada menja recnik, ali neka stoji

private:
    PrefixTree dict;
};

#endif // DICTIONARY_H

