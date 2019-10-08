#ifndef TOWER_H
#define TOWER_H

#include <QObject>

#include "towers_prices.h"
#include "bullets/bullet.h"
#include "towerrangeattack.h"
#include "enemy.h"
#include "towersquareobject.h"

class Hex;

class Tower : public QObject
{
    Q_OBJECT
private:
    const Qt::GlobalColor towerColor;
    const QPointF towerPosition;

    unsigned int attackRange;
    Hex * parentHex;

protected:
    short currentLevel = 1;
    QVector<unsigned int> vectorDamage;
    TowerRangeAttack * towerRangeAttack;

    void setBulletPosAndAddToScene(Bullet * bullet);
    void createNewTowerSquare();

public:
    Tower(unsigned int range, Qt::GlobalColor color, QPointF towerPosition_);

    Qt::GlobalColor getTowerColor() { return towerColor; }
    unsigned int getAttackRange() const { return attackRange; }
    Hex * getParentHex() { return parentHex; }
    short getCurrentLevel() { return currentLevel; }
    unsigned int getDamage() { return vectorDamage[currentLevel-1]; }
    unsigned int getPrice(unsigned short vectorTowerPrices_NR) { return VECTOR_TOWER_PRICES[vectorTowerPrices_NR][currentLevel]; }

    void setParentHex(Hex * h) { parentHex = h; }

    virtual void enemyTargeted(Enemy *e) = 0;

public slots:
    void increaseLevelAndReducePlayerMoney(unsigned short vectorTowerPrices_NR);
    void increaseLevel() { currentLevel++; }
};

#endif // TOWER_H
