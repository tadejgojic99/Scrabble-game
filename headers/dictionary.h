#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <fstream>
#include "headers/prefixtree.h"

class Dictionary
{

public:
    Dictionary(const char* file);   // konstruktor ce ucitavati recnik koji je u tekstualnom formatu, gde se u svakom redu nalazi tacno jedna rec

    bool containsWord(const std::string &word);
    bool noSuccessor(const std::string &word);

    PrefixTree getDictionary() const;
    void setDictionary(PrefixTree &value);   // nisam siguran ni da ce biti potrebno, ne vidim da se tokom igre ikada menja recnik, ali neka stoji

private:
    PrefixTree dict;
};

#endif // DICTIONARY_H
