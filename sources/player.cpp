#include "headers/player.h"
#include <algorithm>

Player::Player()
{
    score = 0;
}

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string &value) {
    name = value;
}

int Player::getScore() const {
    return score;
}
void Player::setScore(int &value) {
    score = value;
}

std::string Player::getHand() const {
    return hand;
}

void Player::setHand(std::string &value) {
    hand = value;
}

void Player::addCard(char card)
{
    hand.push_back(card);
    std::sort(hand.begin(), hand.end());
}
