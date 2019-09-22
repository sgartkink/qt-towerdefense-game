#ifndef YELLOWBULLET_H
#define YELLOWBULLET_H

#include "bullet.h"

class YellowBullet : public Bullet
{
public:
    YellowBullet(Enemy *aimEnemy);
};

#endif // YELLOWBULLET_H
