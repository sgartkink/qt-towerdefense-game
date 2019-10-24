#include "towerrangeattack.h"
#include <QtDebug>

#include "game.h"
extern Game * game;

TowerRangeAttack::TowerRangeAttack(unsigned int r, QPointF hexPosition_)
    : range(r), hexPosition(hexPosition_)
{    
    setPen(pen);

    int vectorHexPoints_previousLength = 0;
    for (int i = 0; i <= r; i++)
        createLeftUpElement(HEX_SIZE*sqrt(3)/2*i, -HEX_SIZE*3/2*i);

    setNewLastPoint();
    for (int  i = 0; i < r; i++)
        createUpElement(HEX_SIZE*sqrt(3)*i, 0);
    if (vectorHexPoints_previousLength == hexPoints_visible.length())
        hexPoints_visible << QPointF(0,0);
    vectorHexPoints_previousLength = hexPoints_visible.length();

    setNewLastPoint();
    for (int i = 0; i < r; i++)
        createRightUpElement(HEX_SIZE*sqrt(3)/2*i, HEX_SIZE*3/2*i);
    if (vectorHexPoints_previousLength == hexPoints_visible.length() && hexPoints_visible.length() != 0
            && hexPosition.y() < game->map->getScene()->height()/2)
        hexPoints_visible << QPointF(1,0);
    vectorHexPoints_previousLength = hexPoints_visible.length();

    setNewLastPoint();
    for (int i = 0; i <= r; i++)
        createRightDownElement(HEX_SIZE*sqrt(3)/2*i, HEX_SIZE*3/2*i);

    setNewLastPoint();
    for (int i = 0; i < r; i++)
        createDownElement(HEX_SIZE*sqrt(3)*i, 0);
    if (vectorHexPoints_previousLength == hexPoints_visible.length() && hexPoints_visible.length() != 0)
        hexPoints_visible << QPointF(1,1);
    vectorHexPoints_previousLength = hexPoints_visible.length();

    setNewLastPoint();
    for (int i = 0; i < r; i++)
        createLeftDownElement(HEX_SIZE*sqrt(3)/2*i, HEX_SIZE*3/2*i);
    if (vectorHexPoints_previousLength == hexPoints_visible.length() && hexPoints_visible.length() != 0)
        hexPoints_visible << QPointF(0,1);

    setPos(hexPosition.x() - range * HEX_SIZE*sqrt(3), hexPosition.y());

    for (auto it = hexPoints_visible.begin(); it != hexPoints_visible.end(); ++it)
        if ((*it).x() == 0 && (*it).y() == 0)
            (*it) = QPointF(mapFromScene(-20,-20));
        else if ((*it).x() == 1 && (*it).y() == 0)
            (*it) = QPointF(mapFromScene(game->map->getScene()->width()-20,-20));
        else if((*it).x() == 1 && (*it).y() == 1)
            (*it) = QPointF(mapFromScene(game->map->getScene()->width()-20,game->map->getScene()->height()-20));
        else if((*it).x() == 0 && (*it).y() == 1)
            (*it) = QPointF(mapFromScene(-20,game->map->getScene()->height()-20));

    QPolygonF hexagon(hexPoints_visible);
    setPolygon(hexagon);
}

void TowerRangeAttack::setNewLastPoint()
{
    lastPoint.setX(hexPoints_calc[hexPoints_calc.length()-1].x());
    lastPoint.setY(hexPoints_calc[hexPoints_calc.length()-1].y());
}

void TowerRangeAttack::createLeftUpElement(double addedX, double addedY)
{
    double addToX = HEX_SIZE/2 + addedX;
    double addToY = HEX_SIZE/2 + addedY;

    createAllPoints(QVector<unsigned short> {0,1,2}, addToX, addToY);
}

void TowerRangeAttack::createUpElement(double addedX, double addedY)
{
    double addToX = lastPoint.x() + HEX_SIZE - 5 + addedX;
    double addToY = lastPoint.y() - HEX_SIZE/2 + addedY;

    createAllPoints(QVector<unsigned short> {6,5,4}, addToX, addToY);
}

void TowerRangeAttack::createRightUpElement(double addedX, double addedY)
{
    double addToX = lastPoint.x() + HEX_SIZE*3/2 + 10 + addedX;
    double addToY = lastPoint.y() + HEX_SIZE + addedY;

    createAllPoints(QVector<unsigned short> {1,0,5}, addToX, addToY);
}

void TowerRangeAttack::createRightDownElement(double addedX, double addedY)
{
    double addToX = lastPoint.x() - HEX_SIZE*sqrt(3)/2 - addedX;
    double addToY = lastPoint.y() + HEX_SIZE/2 + addedY;

    createAllPoints(QVector<unsigned short> {3,4,5}, addToX, addToY);
}

void TowerRangeAttack::createDownElement(double addedX, double addedY)
{
    double addToX = lastPoint.x() - HEX_SIZE/2 - 14 - addedX;
    double addToY = lastPoint.y() + HEX_SIZE/2 + addedY;

    createAllPoints(QVector<unsigned short> {3,2,1}, addToX, addToY);
}

void TowerRangeAttack::createLeftDownElement(double addedX, double addedY)
{    
    double addToX = lastPoint.x() - 3 - addedX;
    double addToY = lastPoint.y() - HEX_SIZE - addedY;

    createAllPoints(QVector<unsigned short> {5,6,1}, addToX, addToY);
}

void TowerRangeAttack::createAllPoints(QVector<unsigned short> anglePoints, double addToX, double addToY)
{
    createPoint(anglePoints[0], addToX, addToY);
    createPoint(anglePoints[1], addToX, addToY);
    createPoint(anglePoints[2], addToX, addToY);
}

void TowerRangeAttack::createPoint(unsigned short anglePoint, double addToX, double addToY)
{
    double angle_deg, angle_rad;

    angle_deg = 60 * anglePoint - 30;
    angle_rad = M_PI / 180 * angle_deg;

    QPointF newPoint = QPointF(x() - HEX_SIZE * cos(angle_rad) + addToX,
                               y() - HEX_SIZE * sin(angle_rad) + addToY);
    hexPoints_calc << newPoint;

    if (hexPosition.x() - range * HEX_SIZE*sqrt(3) + newPoint.x() >= -20
            && hexPosition.x() - range * HEX_SIZE*sqrt(3) + newPoint.x() < game->map->getScene()->width()
            && hexPosition.y() + newPoint.y() >= -21
            && hexPosition.y() + newPoint.y() < game->map->getScene()->height() - 19)
        hexPoints_visible << newPoint;
}
