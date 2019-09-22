#include "bluetower.h"

BlueTower::BlueTower()
    : Tower(2, Qt::blue)
{
}

void BlueTower::enemyTargeted(Enemy *aimEnemy)
{
    BlueBullet * bullet = new BlueBullet(aimEnemy);
    setBulletPosAndAddToScene(bullet);
}
