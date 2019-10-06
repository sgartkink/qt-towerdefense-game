#include "whitebullet.h"
#include <QtDebug>
WhiteBullet::WhiteBullet(Enemy *aimEnemy, unsigned int damage)
    : Bullet(Qt::white, aimEnemy, damage)
{

}
