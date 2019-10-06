#include "yellowbullet.h"

YellowBullet::YellowBullet(Enemy *aimEnemy, unsigned int damage)
    : Bullet(Qt::yellow, aimEnemy, damage)
{

}
