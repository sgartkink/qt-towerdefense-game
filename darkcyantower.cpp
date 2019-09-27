#include "darkcyantower.h"

#include "game.h"
extern Game * game;

DarkCyanTower::DarkCyanTower()
    : Tower(1, Qt::darkCyan)
{
    damage = { 10, 20, 30, 40, 50 };
}

void DarkCyanTower::enemyTargeted(Enemy *aimEnemy)
{
    DarkCyanBullet * bullet = new DarkCyanBullet(aimEnemy, damage[currentLevel-1]);
    setBulletPosAndAddToScene(bullet);
}
