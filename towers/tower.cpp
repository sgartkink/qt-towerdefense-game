#include "tower.h"

#include "game.h"
extern Game * game;

Tower::Tower(unsigned int range, Qt::GlobalColor color, QPointF towerPosition_)
    : towerColor(color), towerPosition(towerPosition_), attackRange(range)
{
    createNewTowerSquare();
}

void Tower::createNewTowerSquare()
{
    TowerSquareObject * towerSquareObject = new TowerSquareObject(towerColor);
    towerSquareObject->setPos(towerPosition.x() - ((currentLevel - 1)*4) + HEX_SIZE/2 - TOWER_SIZE/2,
                              towerPosition.y() - ((currentLevel - 1)*4) + HEX_SIZE/2 - TOWER_SIZE/2);
    towerSquareObject->setRect(0, 0, TOWER_SIZE + ((currentLevel - 1)*8), TOWER_SIZE + ((currentLevel - 1)*8));

    game->map->getScene()->addItem(towerSquareObject);
}

void Tower::setBulletPosAndAddToScene(Bullet *bullet)
{
    bullet->setPos(towerPosition.x() + HEX_SIZE/2 - BULLET_SIZE/2,
                   towerPosition.y() + HEX_SIZE/2 - BULLET_SIZE/2);
    game->map->getScene()->addItem(bullet);
}

void Tower::increaseLevelAndReducePlayerMoney(unsigned short vectorTowerPrices_NR)
{
    game->player->decreaseMoney(getPrice(vectorTowerPrices_NR));
    currentLevel++;
    createNewTowerSquare();
}
