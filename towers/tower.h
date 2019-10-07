#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsRectItem>
#include <QPen>
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
    QPen penTower;
    QVector<Hex*> vectorHexesInRange;
    Hex * parentHex;

protected:
    short currentLevel = 1;
    const unsigned int attackRange;
    QVector<unsigned int> damage;
    TowerRangeAttack * towerRangeAttack;

    void setBulletPosAndAddToScene(Bullet * bullet);
    void createNewTowerSquare();

public:
    Tower(unsigned int range, Qt::GlobalColor color, QPointF towerPosition_);

    unsigned int getAttackRange() const { return attackRange; }
    unsigned int getDamage() { return damage[currentLevel-1]; }
    unsigned int getPrice(unsigned short vectorTowerPrices_NR) { return VECTOR_TOWER_PRICES[vectorTowerPrices_NR][currentLevel]; }
    QVector<Hex*> getVectorHexesInRange() { return vectorHexesInRange; }
    Hex * getParentHex() { return parentHex; }
    Qt::GlobalColor getTowerColor() { return towerColor; }
    short getCurrentLevel() { return currentLevel; }

    void fillVectorHexesInRange(QVector<Hex*> v) { vectorHexesInRange = v; }
    void setParentHex(Hex * h) { parentHex = h; }

    virtual void enemyTargeted(Enemy *e) = 0;

public slots:
    void increaseLevelAndReducePlayerMoney(unsigned short vectorTowerPrices_NR);
    void increaseLevel() { currentLevel++; }
};

#endif // TOWER_H
