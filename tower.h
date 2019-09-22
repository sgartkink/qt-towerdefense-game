#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsRectItem>
#include <QPen>

#include "global_consts.h"
#include "bullet.h"
#include "towerrangeattack.h"
#include "enemy.h"

class Hex;

class Tower : public QGraphicsRectItem
{
private:
    QPen pen;
    QVector<Hex*> vectorHexesInRange;
    Hex * parentHex;

protected:
    const unsigned int attackRange;
    TowerRangeAttack * towerRangeAttack;

    void setBulletPosAndAddToScene(Bullet * bullet);

public:
    Tower(unsigned int range, Qt::GlobalColor color);

    unsigned int getAttackRange() const { return attackRange; }
    QVector<Hex*> getVectorHexesInRange() { return vectorHexesInRange; }
    Hex * getParentHex() { return parentHex; }

    void fillVectorHexesInRange(QVector<Hex*> v) { vectorHexesInRange = v; }
    void setParentHex(Hex * h) { parentHex = h; }

    virtual void enemyTargeted(Enemy *e) = 0;
};

#endif // TOWER_H
