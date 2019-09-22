#include "greentower.h"
#include "game.h"

extern Game * game;

GreenTower::GreenTower()
    : Tower(1, Qt::green)
{
}

void GreenTower::enemyTargeted(Enemy *aimEnemy)
{
    GreenBullet * bullet = new GreenBullet(aimEnemy);
    setBulletPosAndAddToScene(bullet);
}
