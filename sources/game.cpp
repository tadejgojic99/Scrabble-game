#include "headers/game.h"
#include "headers/board.h"
#include <string>
#include <QDebug>
#include <iostream>
#include <algorithm>

Game::Game(QObject *parent) : QObject(parent)
{
    currentPlayer = 0;
    deck.shuffleDeck();
}

int Game::getNumberOfPlayers() const
{
    return numberOfPlayers;
}

void Game::setNumberOfPlayers(int &value)
{
    numberOfPlayers = value;
}

Deck Game::getDeck() const
{
    return deck;
}

void Game::setDeck(Deck &value)
{
    deck = value;
}

QVector<Player> Game::getPlayers() const
{
    return players;
}

void Game::setPlayers(QVector<Player> &value)
{
    players = value;
}

Board Game::getMyBoard() const
{
    return myBoard;
}

void Game::setMyBoard(const Board &value)
{
    myBoard = value;
}

void Game::nextPlayer()
{
    if (currentPlayer == numberOfPlayers-1)
        currentPlayer = 0;
    else
        currentPlayer ++;
}

void Game::start()
{
    createBoard(myBoard);
    sendPlayer(players[currentPlayer]);
}

void Game::manageCards()
{
    std::string hand = players[currentPlayer].getHand();
    for (int y = 0; y < l.LEN_Y; y++)
    {
        for (int x = 0; x < l.LEN_X; x++)
        {
            if (myBoard.getNewLetters()[y][x])
            {
                if (myBoard.getWildcard()[y][x])
                    hand.erase(hand.find('*'), 1);
                else
                    hand.erase(hand.find(myBoard.getLetters()[y][x]), 1);
            }
        }
    }
    hand.erase(std::remove(hand.begin(), hand.end(), '#'), hand.end());
    players[currentPlayer].setHand(hand);
    while (!(deck.isEmpty()) && (players[currentPlayer].getHand().length() < l.HAND_SIZE))
        players[currentPlayer].addCard(deck.getTopCard());
}



void Game::receiveNumberOfPlayers(int number)
{
    numberOfPlayers = number;

    for (int i = 0; i < numberOfPlayers; ++i) {
        Player player;
        player.setName("Player " + to_string(i + 1));
        for (int j = 0; j < Constants::Values::HAND_SIZE; ++j) {
            player.addCard(deck.getTopCard());
        }

        players.push_back(player);
    }
}

void Game::receiveEndTurn(Board tempBoard)
{

    if (validation(tempBoard, true))
    {
        myBoard.setLetters(tempBoard.getLetters());
        myBoard.setNewLetters(tempBoard.getNewLetters());

        myBoard.setWildcard(tempBoard.getWildcard());

        int score = myBoard.calculateScore() + players[currentPlayer].getScore();
        players[currentPlayer].setScore(score);
//        myBoard.clearNewLetters();
        manageCards();

        // provera da li je doslo do pobede
        if (deck.isEmpty() && (players[currentPlayer].getHand().length() == 0))
        {
            victory();
        }
        else
        {

            nextPlayer();
            sendBoard(myBoard);
            sendPlayer(players[currentPlayer]);
        }
    }
    else
    {
        sendBoard(myBoard);
        sendPlayer(players[currentPlayer]);
    }
}

bool Game::validation(Board tempBoard, bool inform) {
    bool test = true;
    // za svako polje proveravamo da li neka rec pocinje na tom polju
    for (int y = 0; y < l.LEN_Y; y++)
    {
        for (int x = 0; x < l.LEN_X; x++)
        {
            if (tempBoard.getLetters()[y][x] != '#')
            {
                // provera da li je ovo pocetak neke reci horizontalno
                if ((tempBoard.firstLeft(x,y) == 1) && ((tempBoard.firstRight(x,y) > 1) || (tempBoard.firstRight(x,y) == 0)))
                {
                    std::string word;
                    std::string word_reverse;
                    int right;

                    if (tempBoard.firstRight(x,y) == 0)
                        right = l.LEN_X - x;
                    else
                        right = tempBoard.firstRight(x,y);

                    for (int i = x; i < x + right; i++)
                    {
                        word.push_back(tempBoard.getLetters()[y][i]);
                    }
                    word_reverse = word;
                    std::reverse(word_reverse.begin(),word_reverse.end());
                    if (word.length() > 3)
                    {
                        if (!(myDictionary.containsWord(word)) && !(myDictionary.containsWord(word_reverse)))
                        {
                            test = false;
                            if (inform)
                            {

                                QMessageBox msgBox;
                                msgBox.setText("Word '" + QString::fromStdString(word) + "' or '" + QString::fromStdString(word_reverse) + "' not in dictionary.");
                                msgBox.exec();
                            }
                        }
                    }
                }
                if  ((tempBoard.firstUp(x,y) == 1) && ((tempBoard.firstDown(x,y) > 1) || (tempBoard.firstDown(x,y) == 0)))
                {
                    std::string word;
                    std::string word_reverse;
                    int down;

                    if (tempBoard.firstDown(x,y) == 0)
                        down = l.LEN_Y - y;
                    else
                        down = tempBoard.firstDown(x,y);

                    for (int i = y; i < y + down; i++)
                    {
                        word.push_back(tempBoard.getLetters()[i][x]);
                    }
                    word_reverse = word;
                    std::reverse(word_reverse.begin(), word_reverse.end());
                    if (word.length() > 3)
                    {

                        if (!(myDictionary.containsWord(word)) && !(myDictionary.containsWord(word_reverse)))
                        {
                            test = false;
                            if (inform)
                            {
                                QMessageBox msgBox;
                                msgBox.setText("Word '" + QString::fromStdString(word) + "' or '" + QString::fromStdString(word_reverse) + "' not in dictionary.");
                                msgBox.exec();
                            }
                        }
                    }
                }
            }
        }
    }

    return test;
}


void Game::receiveRepeatTurn()
{
    myBoard.clearNewLetters();
    resetBoard();

    sendBoard(myBoard);
    sendPlayer(players[currentPlayer]);
}

void Game::resetBoard(){
    std::string oldDeck = deck.getDeck();

    std::string oldHand = players[currentPlayer].getHand();
    oldHand.erase(std::remove(oldHand.begin(), oldHand.end(), '#'), oldHand.end());

    auto newLetterss = myBoard.getNewLetters();
    for(int i=0;i<Constants::LEN_Y;++i){
        for(int j=0; j<Constants::LEN_X;++j){
            if(newLetterss[i][j]){

                if(myBoard.getWildcard()[i][j]) {
                    oldDeck = '*' + oldDeck;
                    oldHand.push_back('*');
                }
                else {
                    oldDeck = myBoard.getLetterValue(i, j) + oldDeck;
                }
                myBoard.setLetterValue('#', j, i);
                myBoard.setWildcard(false, j, i);;
                myBoard.setNewLetterValue(false, j,i);
            }
        }
    }
    deck.setDeck(oldDeck);

    std::sort(oldHand.begin(), oldHand.end());
players[currentPlayer].setHand(oldHand);
}

void Game::receiveRepeatFirstTurn()
{
    resetBoard();
    createBoard(myBoard);
    sendPlayer(players[currentPlayer]);
}

void Game::receiveUpdate(Board tempBoard, std::string cards)
{
    myBoard.setLetters(tempBoard.getLetters());
    myBoard.addNewLetter(tempBoard.getNewLetters());
    myBoard.setWildcard(tempBoard.getWildcard());
    players[currentPlayer].setHand(cards);

    sendBoard(myBoard);
    sendPlayer(players[currentPlayer]);
}

void Game::calculateSuggestion()
{
    int line = -1;
    int column = -1;
    int score = 0;
    std::string word = "";
    QMessageBox msgBox;
    std::string msg_text;
    QVector<QVector<char>> letters = myBoard.getLetters();
    std::string bestWord = "";
    // horizontalna provera
    for (int r = 0; r < Constants::LEN_Y; r++)
    {
        bool test = false;
        QVector<char> lett = letters[r];
        for(int c = 0; c < Constants::LEN_X; c++)     // provera da li postoji bar jedno slovo u liniji
        {

            char letter = lett[c];
            std::string output = "";
            output.push_back(letter);
            if (letter != '#' ){
                test = true;
            }
        }
        if (test) // ako nema cak ni slovo u liniji, ne proveravamo nista u toj liniji
        {
            std::string temp_rack = players[currentPlayer].getHand();
            std::string rack;

            for (size_t i = 0; i < temp_rack.length(); i++){
                if (temp_rack.at(i) != '*' && temp_rack.at(i) != '#')
                    rack.push_back(temp_rack.at(i));
            }
            for (int c = 0; c < Constants::LEN_X; c++){
                if (myBoard.getLetters()[r][c] != '#')
                    rack += myBoard.getLetters()[r][c];
            }
            unordered_map<char, int> choice;
            for(size_t i = 0; i < rack.length(); i++){
                if(choice.find(rack[i]) == choice.end())
                    choice[toupper(rack[i])] = 0;
                choice[toupper(rack[i])]++;
            }

            QVector<std::string> found_words;
            std::string word;
            constructWords(choice, word, found_words);  // trazimo sve moguce reci
           int n = found_words.size();
            for(int j=0;j<n;++j)                // prelistavamo sve pronadjene reci
            {
                if (found_words[j].length() < 4)
                    continue;
                if (!(found_words[j].length() > Constants::LEN_X))
                {
                    for (size_t c = 0; c < (Constants::LEN_X - found_words[j].length()); c++)      // za svaku rec pokusavamo da je stavimo na svako polje reda
                    {
                        test = true;
                        bool flag = false;
                        bool flag2 = false;
                        bool flag3 = true;
                        std::string hand = players[currentPlayer].getHand();
                        for (size_t i = 0; i < found_words[j].length(); i++)     // kontrolisemo poziciju svakog slova na tabli
                        {
                            if ((found_words[j].at(i) != myBoard.getLetters()[r][c+i]) && (myBoard.getLetters()[r][c+i] != '#')) // ako postoji neka nepravilnost
                                test = false;       // onda se rec ne racuna
                            if(found_words[j].at(i) == myBoard.getLetters()[r][c+i])   // provera da li se poklapa sa vec nekim slovom na tabli
                                flag = true;
                            if (test && (myBoard.getLetters()[r][c+i] == '#'))
                                flag2 = true;
                            if (test && ((myBoard.getLetters()[r][c+i] == '#') && (hand.find(found_words[j].at(i)) == std::string::npos)))
                                flag3 = false;
                            else if ((myBoard.getLetters()[r][c+i] == '#') && (hand.find(found_words[j].at(i)) != std::string::npos))
                                hand.erase(hand.find(found_words[j].at(i)));
                        }
                        if (test && flag && flag2 && flag3)   // ako mozemo da nastavimo, proveravamo rezultat reci
                        {
                            Board tempBoard = Board();
                            tempBoard.setLetters(myBoard.getLetters());
                            for (size_t i = 0; i < found_words[j].length(); i++)
                            {
                                if (myBoard.getLetters()[r][c+i] == '#')
                                {
                                    tempBoard.setLetterValue(found_words[j].at(i),c+i,r);
                                    tempBoard.setNewLetterValue(true,c+i,r);
                                }
                            }
                            if (validation(tempBoard,false))
                            {
                                if(tempBoard.calculateScore() > score)
                                {
                                    score = tempBoard.calculateScore();
                                    word = found_words[j];
                                    column = c;
                                    line = r;
                                    bestWord = word;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    msgBox.setWindowTitle("Horizontally");
    if (bestWord != "")
        msg_text = " Found word: " + bestWord + "\n score: " + to_string(score) + "\n line: " + to_string(line) + "\n column: " + to_string(column);
    else
        msg_text = "Haven't found a horizontal word longer than 3 characters!";
    std::string pom = msg_text;
    msgBox.setText(QString::fromStdString(pom));
    msgBox.exec();

    bestWord = "";
    word = "";
    line = -1;
    column = -1;
    score = 0;
    for (int c = 0; c < Constants::LEN_X; c++)
    {
        bool test = false;
        for(int r = 0; r < Constants::LEN_X; r++)
        {
            if (myBoard.getLetters()[r][c] != '#' )
                test = true;
        }
        if (test)
        {
            std::string temp_rack = players[currentPlayer].getHand();
            std::string rack;

            for (size_t i = 0; i < temp_rack.length(); i++)
                if (temp_rack.at(i) != '*')
                    rack.push_back(temp_rack.at(i));

            for (int r = 0; r < Constants::LEN_Y; r++)
                if (myBoard.getLetters()[r][c] != '#')
                    rack += myBoard.getLetters()[r][c];

            unordered_map<char, int> choice;
            for(size_t i = 0; i < rack.length(); i++){
                if(choice.find(rack[i]) == choice.end())
                    choice[toupper(rack[i])] = 0;
                choice[toupper(rack[i])]++;
            }

            QVector<std::string> found_words;
            std::string word;
            constructWords(choice, word, found_words);

            for(auto it = found_words.begin(); it != found_words.end(); it++)
            {
                if (it->length() < 3)
                    continue;
                if (!(it->length() > Constants::LEN_Y))
                {
                    for (size_t r = 0; r < (Constants::LEN_Y - it->length()); r++)
                    {
                        test = true;
                        bool flag = false;
                        bool flag2 = false;
                        bool flag3 = true;
                        std::string hand = players[currentPlayer].getHand();
                        for (size_t i = 0; i < it->length(); i++)
                        {
                            if ((it->at(i) != myBoard.getLetters()[r+i][c]) && (myBoard.getLetters()[r+i][c] != '#'))
                                test = false;
                            if(it->at(i) == myBoard.getLetters()[r+i][c])
                                flag = true;
                            if (test && (myBoard.getLetters()[r+i][c] == '#'))
                                flag2 = true;
                            if (test && ((myBoard.getLetters()[r+i][c] == '#') && (hand.find(it->at(i)) == std::string::npos)))
                                flag3 = false;
                            else if ((myBoard.getLetters()[r+i][c] == '#') && (hand.find(it->at(i)) != std::string::npos))
                                hand.erase(hand.find(it->at(i)));
                        }
                        if (test && flag && flag2 && flag3)
                        {
                            Board tempBoard = Board();
                            tempBoard.setLetters(myBoard.getLetters());
                            for (size_t i = 0; i < it->length(); i++)
                            {
                                if (myBoard.getLetters()[r+i][c] == '#')
                                {
                                    tempBoard.setLetterValue(it->at(i),c,r+i);
                                    tempBoard.setNewLetterValue(true,c,r+i);
                                }
                            }
                            if (validation(tempBoard,false))
                            {
                                if(tempBoard.calculateScore() > score)
                                {
                                    score = tempBoard.calculateScore();
                                    word = *it;
                                    column = c;
                                    line = r;
                                    bestWord = word;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    msgBox.setWindowTitle("Vertically");
    if (bestWord != "")
        msg_text = " Found word: " + bestWord + "\n score: " + to_string(score) + "\n line: " + to_string(line) + "\n column: " + to_string(column);
    else
        msg_text = "Haven't found a vertical word longer than 3 characters!";
    pom = msg_text;
    msgBox.setText(QString::fromStdString(pom));
    msgBox.exec();
}



void Game::victory()
{
    Constants* constants = new Constants();
    // igracu koji je odigrao sve karte dodajemo vrednosti preostalih karata u rukama protivnika
    for (int i = 0; i < numberOfPlayers; i++)
    {
        if (i != currentPlayer)
        {
            for (int x = 0; x < static_cast<int>(players[i].getHand().length()); x++)
                if (players[i].getHand().at(x) != '*') {
                    int tmpPos = tolower(players[i].getHand().at(x)) - 'a';
                    int tmp = constants->LETTER_SCORES[tmpPos];
                    int tmpScore = players[currentPlayer].getScore();
                    int scoreSet = tmpScore + tmp;
                    players[currentPlayer].setScore(scoreSet);
                }
        }
    }
    int topPlayer = 0;
    for (int i = 1; i < numberOfPlayers; i++)
    {
        if (players[topPlayer].getScore() < players[i].getScore())
            topPlayer = i;
    }

    sendEnd(players[topPlayer]);
}



void Game::constructWords(std::unordered_map<char, int> &choice, std::string &curWord, QVector<std::string > &words)
{
    for(auto it = choice.begin(); it != choice.end(); it++){
        if(it->second <= 0  || it->first == '#')     // ako se karakter pojavljuje <=0 puta, tj ne pojavljuje se, nastaviti
            continue;

        curWord += it->first;   // trenutnoj reci dodajemo tekuci karakter
//        std::cout << curWord<<std::endl;
        it->second--;           // posto je karakter iskoriscen smanjujemo broj pojavljivanja
        if(myDictionary.containsWord(curWord))          // proveravamo da li tekuca rec postoji u recniku
            words.push_back(curWord);     // ukoliko postoji dodajemo je u vektor reci
        if (!(myDictionary.noSuccessor(curWord)))     // ako iz te reci ne postoji nastavak, nema poente proveravati dalje
            constructWords(choice, curWord, words);               // rekurzivno pozivamo funkciju da bismo mogli da proverimo sve moguce kombinacije sa nasim slovima

        choice[curWord.back()]++;   // povecavamo brojac pojavljivanja poslednjeg iskoriscenog karaktera, da bismo se vratili na pocetno stanje
        curWord.pop_back();         // uklanjamo poslednji karakter iz tekuce reci da bismo se vratili na pocetno stanje
    }
}

void Game::receiveRequestSuggestion()
{
    calculateSuggestion();
}


