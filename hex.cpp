#include "hex.h"

#include "game.h"
extern Game * game;

Hex::Hex(int x_, int y_)
    : xOffset(x_), xAxial(offsetToAxial(x_, y_)), yCord(y_), zCord(-xAxial-y_)
{
    QVector<QPointF> hexPoints;
    for (int i = 0; i <= 6; i++)
    {
        double angle_deg = 60 * i - 30;
        double angle_rad = M_PI / 180 * angle_deg;
        hexPoints << QPointF(HEX_SIZE * cos(angle_rad) + HEX_SIZE/2,
                             HEX_SIZE * sin(angle_rad) + HEX_SIZE/2);
    }
    QPolygonF hexagon(hexPoints);

    setPolygon(hexagon);
    setAcceptHoverEvents(true);

    setBrush(brush);
    setPen(pen);
}

void Hex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->map->hexWasClicked(this);
}

void Hex::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    changeHexBrushColor(HEX_UNDER_MOUSE_COLOR);

    changeOpacityBasedOnHexAndTower(OPACITY_HOVER, true);
}

void Hex::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (isPath)
        changeHexBrushColor(PATH_COLOR);
    else
        changeHexBrushColor(HEX_NORMAL_COLOR);

    changeOpacityBasedOnHexAndTower(OPACITY_NORMAL, false);
}

void Hex::changeOpacityBasedOnHexAndTower(qreal opacity, bool checkTower)
{
    if (game->map->getActiveHex())
    {
        if (!game->map->getActiveHex()->getTower() &&
            this != game->map->getActiveHex())
            {
                if (checkTower)
                {
                    if (tower)
                        game->map->changeOpacityHexesOutOfReach(opacity, this);
                }
                else
                    game->map->changeOpacityHexesOutOfReach(opacity, this);
            }
    }
    else
        if (this != game->map->getActiveHex())
            game->map->changeOpacityHexesOutOfReach(opacity, this);
}

void Hex::changeHexBrushColor(Qt::GlobalColor color)
{
    brush.setColor(color);
    setBrush(brush);
}
