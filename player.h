#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QtDebug>


class Player : public QObject
{
    Q_OBJECT
private:
    unsigned int money = 2000;

public:
    Player();

    unsigned int getMoney() { return money; }

    void updateUpgradeAndBuyButtons();

public slots:
    void increaseMoney(unsigned int increased);
    void decreaseMoney(unsigned int decreased);
};

#endif // PLAYER_H
