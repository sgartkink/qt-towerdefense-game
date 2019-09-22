#ifndef GREENBULLET_H
#define GREENBULLET_H

#include "bullet.h"

class GreenBullet : public Bullet
{
public:
    GreenBullet(Enemy *aimEnemy);
};

#endif // GREENBULLET_H
