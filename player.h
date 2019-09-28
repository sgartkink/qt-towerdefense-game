#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QtDebug>


class Player : public QObject
{
    Q_OBJECT
private:
    unsigned int money = 500;

public:
    Player();

    unsigned int getMoney() { return money; }

public slots:
    void increaseMoney(unsigned int increased) { money += increased; }
    void decreaseMoney(unsigned int decreased) { money -= decreased; }
};

#endif // PLAYER_H
