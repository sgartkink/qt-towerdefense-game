#include "darkcyantower.h"
#include "game.h"

extern Game * game;

DarkCyanTower::DarkCyanTower()
    : Tower(1, Qt::darkCyan)
{
}

void DarkCyanTower::enemyTargeted(Enemy *aimEnemy)
{
    DarkCyanBullet * bullet = new DarkCyanBullet(aimEnemy);
    setBulletPosAndAddToScene(bullet);
}
