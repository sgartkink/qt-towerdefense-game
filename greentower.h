#ifndef GREENTOWER_H
#define GREENTOWER_H

#include "tower.h"
#include "greenbullet.h"

class GreenTower : public Tower
{
public:
    GreenTower();

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // GREENTOWER_H
