#ifndef REDTOWER_H
#define REDTOWER_H

#include "tower.h"
#include "bullets/darkcyanbullet.h"

class DarkCyanTower : public Tower
{
public:
    DarkCyanTower(QPointF towerPosition);

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // REDTOWER_H
