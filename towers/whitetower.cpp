#include "whitetower.h"

#include "game.h"
extern Game * game;

WhiteTower::WhiteTower(QPointF towerPosition)
    : Tower(3, Qt::white, towerPosition)
{
    vectorDamage = { 10, 20, 30, 40, 50 };
}

void WhiteTower::enemyTargeted(Enemy *aimEnemy)
{
    WhiteBullet * bullet = new WhiteBullet(aimEnemy, vectorDamage[currentLevel-1]);
    setBulletPosAndAddToScene(bullet);
}
