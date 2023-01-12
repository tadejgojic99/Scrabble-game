#include "headers/prefixtree.h"
#include <iostream>

PrefixTree::PrefixTree():endOfWord(false), successor{} {}


PrefixTree::~PrefixTree()
{
    for (int i = 0; i < PrefixTree::NUM_OF_CHARS; ++i) {
        delete successor[i];        // brisemo svaki nastavak, koji je i sam prefiksno stablo
    }
}

void PrefixTree::insert(const std::string &word)
{
    if(word.empty())
        return;

    return insert(word, 0);
}


void PrefixTree::insert(const std::string &word, int cur){
    if(cur == static_cast<int>((word.length()))){
        endOfWord = true;
        return;
    }

    int index = static_cast<int>(tolower(word.at(cur))) - static_cast<int>('a');
    if(successor[index] == NULL)
        successor[index] = new PrefixTree();
    successor[index]->insert(word, cur+1);
}


int PrefixTree::find(const std::string &word)
{
    if(word.empty())
        return 0;

    return find(word, 0);
}



int PrefixTree::find(const std::string &word, int cur)
{
    if(cur == static_cast<int>(word.length()))
        return this->endOfWord ? int(PrefixTree::WORD) : int(PrefixTree::PREFIX);     // ukoliko smo zaista na kraju reci, vraca se Trie::WORD, u suprotnom, vraca se TRIE::PREFIX

    int index = static_cast<int>(tolower(word.at(cur))) - static_cast<int>('a');


    if(successor[index] == NULL)
        return int(PrefixTree::NONE);
    return successor[index]->find(word, cur+1);
}

bool PrefixTree::noSuccessor(const std::string &word)
{
    if (word.empty())
        return false;
    int ind = static_cast<int>(tolower(word.at(0)));
    int index = ind - static_cast<int>('a');


    if (successor[index] == NULL)
        return true;
    std::string tmp1 = word.substr(1, word.length() - 1);
    return successor[index]->noSuccessor(tmp1);
}

