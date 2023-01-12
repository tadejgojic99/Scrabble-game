#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{

public:
    Player();

    // getter-i i setter-i
    QString getName() const;
    void setName(const QString &value);

    int getScore() const;
    void setScore(int &value);

    QString getHand() const;
    void setHand(QString &value);
    QString getCards() const;
    void setCards(const QString &value);
    void addCard(QChar card);

private:
    QString name;
    int score;
    QString hand;
    QString cards;
};



#endif // PLAYER_H
