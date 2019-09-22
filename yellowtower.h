#ifndef YELLOWTOWER_H
#define YELLOWTOWER_H

#include "tower.h"
#include "yellowbullet.h"

class YellowTower : public Tower
{
public:
    YellowTower();

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // YELLOWTOWER_H
