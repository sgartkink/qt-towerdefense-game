#include "hex.h"
#include "game.h"

extern Game * game;
Hex::Hex(int x_, int y_, QGraphicsItem * parent)
    : xOffset(x_), xAxial(offsetToAxial(x_, y_)), yCord(y_), zCord(-xAxial-y_)
{
    QVector<QPointF> hexPoints;
    for (int i = 0; i <= 6; i++)
    {
        double angle_deg = 60 * i - 30;
        double angle_rad = M_PI / 180 * angle_deg;
        hexPoints << QPointF(HEX_SIZE * cos(angle_rad) + HEX_SIZE/2,
                             HEX_SIZE * sin(angle_rad) + HEX_SIZE/2
                             );
    }
    QPolygonF hexagon(hexPoints);

    setPolygon(hexagon);
    setAcceptHoverEvents(true);

    setBrush(brush);
    setPen(pen);
}

void Hex::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    changeHexBrushAndUpdate(HEX_UNDER_MOUSE_COLOR);
}

void Hex::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (inRangeChosenHexWithTower)
        changeHexBrushAndUpdate(HEX_IN_TOWER_RANGE_COLOR);
    else
        changeHexBrushAndUpdate(HEX_NORMAL_COLOR);
}

void Hex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->map->hexWasClicked(this);
}

void Hex::changeHexBrushAndUpdate(Qt::GlobalColor color)
{
    brush.setColor(color);
    setBrush(brush);
    update();
}
