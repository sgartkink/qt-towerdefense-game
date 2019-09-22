#ifndef BLUETOWER_H
#define BLUETOWER_H

#include "tower.h"
#include "bluebullet.h"

class BlueTower : public Tower
{
public:
    BlueTower();

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // BLUETOWER_H
