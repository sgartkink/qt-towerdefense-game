#include "pathforenemy.h"

#include "game.h"
extern Game * game;

PathForEnemy::PathForEnemy()
{
    addHexToPath(0,0);
    addHexToPath(0,1);
    addHexToPath(0,2);
    addHexToPath(0,3);
    addHexToPath(0,4);
    addHexToPath(0,5);
    addHexToPath(0,6);
    addHexToPath(0,7);
    addHexToPath(1,7);
    addHexToPath(2,7);
    addHexToPath(2,6);
    addHexToPath(2,5);
    addHexToPath(2,4);
    addHexToPath(2,3);
    addHexToPath(2,2);
    addHexToPath(2,1);
    addHexToPath(2,0);
    addHexToPath(3,0);
    addHexToPath(4,0);
    addHexToPath(4,1);
    addHexToPath(4,2);
    addHexToPath(4,3);
    addHexToPath(4,4);
    addHexToPath(4,5);
    addHexToPath(4,6);
    addHexToPath(4,7);
    addHexToPath(5,7);
    addHexToPath(6,7);
    addHexToPath(6,6);
    addHexToPath(6,5);
    addHexToPath(6,4);
    addHexToPath(6,3);
    addHexToPath(6,2);
    addHexToPath(6,1);
    addHexToPath(6,0);
    addHexToPath(7,0);
}

QPointF PathForEnemy::addHexToPath(int x, int y)
{
    QPointF point = getHexCenter(x,y);
    points.append(point);

    changeHexColor(x, y);
    game->map->getHex(x,y)->setPath(true);

    return getHexCenter(x, y);
}

void PathForEnemy::changeHexColor(int x, int y)
{
    game->map->getHex(x,y)->changeHexBrushColor(PATH_COLOR);
}

QPointF PathForEnemy::getHexCenter(int x, int y)
{
    return QPointF(getHexCenterX(x,y), getHexCenterY(x,y));
}

qreal PathForEnemy::getHexCenterX(int x, int y)
{
    return game->map->getHex(x,y)->x() + HEX_SIZE/2;
}

qreal PathForEnemy::getHexCenterY(int x, int y)
{
    return game->map->getHex(x,y)->y() + HEX_SIZE/2;
}
