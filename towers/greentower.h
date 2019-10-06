#ifndef GREENTOWER_H
#define GREENTOWER_H

#include "tower.h"
#include "bullets/greenbullet.h"

class GreenTower : public Tower
{
public:
    GreenTower(QPointF towerPosition);

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // GREENTOWER_H
