#ifndef DARKCYANBULLET_H
#define DARKCYANBULLET_H

#include "bullet.h"

class DarkCyanBullet : public Bullet
{
public:
    DarkCyanBullet(Enemy *aimEnemy, unsigned int damage);
};

#endif // DARKCYANBULLET_H
