#include "dictionary.h"
#include <iostream>
#include <QString>

Dictionary::Dictionary(const char *file)
{
    std::ifstream ifs (file);   // uzimam fajl
    std::string word;
    while(ifs >> word) {        // koristicemo obican std::string, operator >> ne radi za QString, a mrzi me da ga overload-ujem
        dict.insert((QString::fromStdString(word)));
    }
}

bool Dictionary::containsWord(const QString &word)
{
    return dict.find(word) == int(PrefixTree::WORD);
}

PrefixTree Dictionary::getDictionary() const
{
    return dict;
}

void Dictionary::setDictionary(PrefixTree &value)
{
    dict = value;
}

bool Dictionary::noSuccessor(const QString &word)
{
    // da li se u dict ne nalazi ta rec
    return dict.noSuccessor(word);
}

