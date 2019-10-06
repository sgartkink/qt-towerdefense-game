#ifndef YELLOWBULLET_H
#define YELLOWBULLET_H

#include "bullet.h"

class YellowBullet : public Bullet
{
public:
    YellowBullet(Enemy *aimEnemy, unsigned int damage);
};

#endif // YELLOWBULLET_H
