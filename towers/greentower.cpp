#include "greentower.h"
#include "game.h"

extern Game * game;

GreenTower::GreenTower(QPointF towerPosition)
    : Tower(1, Qt::green, towerPosition)
{
    vectorDamage = { 10, 20, 30, 40, 50 };
}

void GreenTower::enemyTargeted(Enemy *aimEnemy)
{
    GreenBullet * bullet = new GreenBullet(aimEnemy, vectorDamage[currentLevel-1]);
    setBulletPosAndAddToScene(bullet);
}
