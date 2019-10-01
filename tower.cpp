#include "tower.h"

#include "game.h"
extern Game * game;

void Tower::setBulletPosAndAddToScene(Bullet *bullet)
{
    bullet->setPos(x() + HEX_SIZE/2 - BULLET_SIZE/2, y() + HEX_SIZE/2 - BULLET_SIZE/2);
    game->map->getScene()->addItem(bullet);
}

Tower::Tower(unsigned int range, Qt::GlobalColor color)
    : attackRange(range)
{
    penTower.setColor(color);
    setPen(penTower);
    setRect(0, 0, HEX_SIZE, HEX_SIZE);
}

void Tower::increaseLevelAndReducePlayerMoney(unsigned short vectorTowerPrices_NR)
{
    game->player->decreaseMoney(getPrice(vectorTowerPrices_NR));
    currentLevel++;
}
