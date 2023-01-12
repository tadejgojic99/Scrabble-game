#include "headers/dictionary.h"
#include <iostream>
#include <string>

Dictionary::Dictionary(const char *file)
{
    std::ifstream ifs (file);   // uzimam fajl
    std::string word;
    while(ifs >> word) {
        dict.insert(word);
    }
}

bool Dictionary::containsWord(const std::string &word)
{
   int x = dict.find(word);
           return x== int(PrefixTree::WORD);
}

PrefixTree Dictionary::getDictionary() const
{
    return dict;
}

void Dictionary::setDictionary(PrefixTree &value)
{
    dict = value;
}

bool Dictionary::noSuccessor(const std::string &word)
{
    // da li se u dict ne nalazi ta rec
    return dict.noSuccessor(word);
}

