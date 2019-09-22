#include "yellowtower.h"
#include "game.h"

extern Game * game;

YellowTower::YellowTower()
    : Tower(2, Qt::yellow)
{
}

void YellowTower::enemyTargeted(Enemy *aimEnemy)
{
    YellowBullet * bullet = new YellowBullet(aimEnemy);
    setBulletPosAndAddToScene(bullet);
}
