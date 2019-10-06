#ifndef WHITETOWER_H
#define WHITETOWER_H

#include "tower.h"
#include "bullets/whitebullet.h"

class WhiteTower : public Tower
{
public:
    WhiteTower(QPointF towerPosition);

    virtual void enemyTargeted(Enemy *aimEnemy);
};

#endif // WHITETOWER_H
