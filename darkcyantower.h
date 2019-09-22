#ifndef REDTOWER_H
#define REDTOWER_H

#include "tower.h"
#include "darkcyanbullet.h"

class DarkCyanTower : public Tower
{
public:
    DarkCyanTower();

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // REDTOWER_H
