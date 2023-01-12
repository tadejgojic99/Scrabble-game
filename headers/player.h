#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{

public:
    Player();

    std::string getName() const;
    void setName(const std::string &value);

    int getScore() const;
    void setScore(int &value);

    std::string getHand() const;
    void setHand(std::string &value);
    std::string getCards() const;
    void setCards(const std::string &value);
    void addCard(char card);

private:
    std::string name;
    int score;
    std::string hand;
    std::string cards;
};



#endif // PLAYER_H
