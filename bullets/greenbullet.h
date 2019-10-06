#ifndef GREENBULLET_H
#define GREENBULLET_H

#include "bullet.h"

class GreenBullet : public Bullet
{
public:
    GreenBullet(Enemy *aimEnemy, unsigned int damage);
};

#endif // GREENBULLET_H
