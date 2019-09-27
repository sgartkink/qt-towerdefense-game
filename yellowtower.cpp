#include "yellowtower.h"
#include "game.h"

extern Game * game;

YellowTower::YellowTower()
    : Tower(2, Qt::yellow)
{
    damage = { 10, 20, 30, 40, 50 };
}

void YellowTower::enemyTargeted(Enemy *aimEnemy)
{
    YellowBullet * bullet = new YellowBullet(aimEnemy, damage[currentLevel-1]);
    setBulletPosAndAddToScene(bullet);
}
