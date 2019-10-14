#include "yellowtower.h"
#include "game.h"

extern Game * game;

YellowTower::YellowTower(QPointF towerPosition)
    : Tower(2, Qt::yellow, towerPosition)
{
    vectorDamage = { 1, 20, 30, 40, 50 };
}

void YellowTower::enemyTargeted(Enemy *aimEnemy)
{
    YellowBullet * bullet = new YellowBullet(aimEnemy, vectorDamage[currentLevel-1]);
    setBulletPosAndAddToScene(bullet);
}
