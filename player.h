#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QtDebug>

class Player : public QObject
{
    Q_OBJECT
private:
    unsigned int money = 2000;
    int hp = 10;

public:
    Player();

    unsigned int getMoney() { return money; }
    int getHp() { return hp; }

    void updateUpgradeAndBuyButtons();

public slots:
    void increaseMoney(unsigned int increased);
    void decreaseMoney(unsigned int decreased);

    void increaseHp(int increased);
    void decreaseHp(int decreased);
};

#endif // PLAYER_H
