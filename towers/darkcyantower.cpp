#include "darkcyantower.h"

#include "game.h"
extern Game * game;

DarkCyanTower::DarkCyanTower(QPointF towerPosition)
    : Tower(1, Qt::darkCyan, towerPosition)
{
    vectorDamage = { 10, 20, 30, 40, 50 };
}

void DarkCyanTower::enemyTargeted(Enemy *aimEnemy)
{
    DarkCyanBullet * bullet = new DarkCyanBullet(aimEnemy, vectorDamage[currentLevel-1]);
    setBulletPosAndAddToScene(bullet);
}
