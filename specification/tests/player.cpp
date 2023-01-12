#include "player.h"

Player::Player()
{
    score = 0;  // ima mi smisla da ovo bude u konstruktoru
}

QString Player::getName() const {
    return name;
}

void Player::setName(const QString &value) {
    name = value;
}

int Player::getScore() const {
    return score;
}
void Player::setScore(int &value) {
    score = value;
}

QString Player::getHand() const {
    return hand;
}

void Player::setHand(QString &value) {
    hand = value;
}

void Player::addCard(QChar card)
{
    hand.append(card);    // dodajem kartu u ruke
    std::sort(hand.begin(), hand.end());   // sortiraju se karte u ruci, u rastucem poretku
}
