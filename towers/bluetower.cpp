#include "bluetower.h"

BlueTower::BlueTower(QPointF towerPosition)
    : Tower(2, Qt::blue, towerPosition)
{
    damage = { 10, 20, 30, 40, 50 };
}

void BlueTower::enemyTargeted(Enemy *aimEnemy)
{
    BlueBullet * bullet = new BlueBullet(aimEnemy, damage[currentLevel-1]);
    setBulletPosAndAddToScene(bullet);
}
