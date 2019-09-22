#include "whitetower.h"

#include "game.h"
extern Game * game;

WhiteTower::WhiteTower()
    : Tower(3, Qt::white)
{
}

void WhiteTower::enemyTargeted(Enemy *aimEnemy)
{
    WhiteBullet * bullet = new WhiteBullet(aimEnemy);
    setBulletPosAndAddToScene(bullet);
}
