#include "prefixtree.h"
#include <iostream>
#include <QChar>
PrefixTree::PrefixTree():endOfWord(false), successor{}{}


PrefixTree::~PrefixTree()
{
    for (int i = 0; i < PrefixTree::NUM_OF_CHARS; ++i) {
        delete successor[i];        // brisemo svaki nastavak, koji je i sam prefiksno stablo
    }
}

void PrefixTree::insert(const QString &word)
{
    if(word.isEmpty())
        return;

   // moracu izgleda da pravim novi metod, ili da overload-ujem ovaj, jer treba pratiti na kom je mestu u stringu(npr unosim abcd, a imam vec ab,
   // onda treba proveriti rekurzivno da li rec vec postoji)
   // EDIT: mozda je bolje overload, jer je razumljivije

    return insert(word, 0);     // pozivam funkciju
   // overload: return insert(word, 0)   logicno i sigurno mi je da se uvek krece od nultog indeksa, pa se dalje proverava
}


void PrefixTree::insert(const QString &word, int cur){
    if(cur == (int)(word.length())){       // ukoliko smo dosli do kraja, uneta je cela rec
        endOfWord = true;           // aktivira indikator kraja reci
        return;
    }

    int index = static_cast<int>(word.toLower().at(cur).toLatin1()) - static_cast<int>('a');    // racunamo nastavak reci
    if(successor[index] == NULL)            // ukoliko ne postoji
        successor[index] = new PrefixTree();      // kreiramo je
    successor[index]->insert(word, cur+1);  // i ubacujemo
}


int PrefixTree::find(const QString &word)
{
    if(word.isEmpty())
        return 0;   // oznacava praznu rec

    // morace i ovde overload, jer treba da ide slovo po slovo
    // znaci overload: return find(word, 0)
    return find(word, 0);  // poziv funkcije
}



int PrefixTree::find(const QString &word, int cur)
{
    if(cur == word.length())        // ukoliko smo dosli do kraja reci
        return endOfWord ? int(PrefixTree::WORD) : int(PrefixTree::PREFIX);     // ukoliko smo zaista na kraju reci, vraca se Trie::WORD, u suprotnom, vraca se TRIE::PREFIX

    int index = static_cast<int>(word.toLower().at(cur).toLatin1()) - static_cast<int>('a');   // ponovo, racunamo nastavak reci


    if(successor[index] == NULL)            // i ukoliko ne postoji
        return int(PrefixTree::NONE);             // vracamo Trie::NONE
    return successor[index]->find(word, cur+1); // u suprotnom, rekurzivno nastavljamo
}

bool PrefixTree::noSuccessor(const QString &word)
{
    if (word.isEmpty())     // ukoliko smo na kraju reci, vracamo false
        return false;
    else if (successor[static_cast<int>(word.toLower().at(0).toLatin1()) - static_cast<int>('a')] == NULL) // ako ne postoji nastavak
        return true;    // onda vracamo true

    return successor[static_cast<int>(word.at(0).toLatin1()) - static_cast<int>('A')]->noSuccessor(word.mid(1,word.size()-1));    // inace, nastavljamo rekurzivno sa nastavkom, eliminisuci prvo slovo reci
}

