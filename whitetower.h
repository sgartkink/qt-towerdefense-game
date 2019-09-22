#ifndef WHITETOWER_H
#define WHITETOWER_H

#include "tower.h"
#include "whitebullet.h"

class WhiteTower : public Tower
{
public:
    WhiteTower();

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // WHITETOWER_H
