#include "greenbullet.h"

GreenBullet::GreenBullet(Enemy *aimEnemy, unsigned int damage)
    : Bullet(Qt::green, aimEnemy, damage)
{

}
