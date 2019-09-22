#ifndef WHITEBULLET_H
#define WHITEBULLET_H

#include "bullet.h"

class WhiteBullet : public Bullet
{
public:
    WhiteBullet(Enemy *aimEnemy);
};

#endif // WHITEBULLET_H
