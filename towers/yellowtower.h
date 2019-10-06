#ifndef YELLOWTOWER_H
#define YELLOWTOWER_H

#include "tower.h"
#include "bullets/yellowbullet.h"

class YellowTower : public Tower
{
public:
    YellowTower(QPointF towerPosition);

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // YELLOWTOWER_H
