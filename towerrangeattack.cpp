#include "towerrangeattack.h"
#include <QtDebug>

#include "game.h"
extern Game * game;

TowerRangeAttack::TowerRangeAttack(unsigned int r, QPointF hexPosition)
    : range(r)
{    
    setPen(pen);

    for (int i = 0; i <= r; i++)
        createLeftUpElement(HEX_SIZE*sqrt(3)/2*i, -HEX_SIZE*3/2*i);

    setNewLastPoint();
    for (int  i = 0; i < r; i++)
        createUpElement(HEX_SIZE*sqrt(3)*i, 0);

    setNewLastPoint();
    for (int i = 0; i < r; i++)
        createRightUpElement(HEX_SIZE*sqrt(3)/2*i, HEX_SIZE*3/2*i);

    setNewLastPoint();
    for (int i = 0; i <= r; i++)
        createRightDownElement(HEX_SIZE*sqrt(3)/2*i, HEX_SIZE*3/2*i);

    setNewLastPoint();
    for (int i = 0; i < r; i++)
        createDownElement(HEX_SIZE*sqrt(3)*i, 0);

    setNewLastPoint();
    for (int i = 0; i < r; i++)
        createLeftDownElement(HEX_SIZE*sqrt(3)/2*i, HEX_SIZE*3/2*i);

    setPos(hexPosition.x() - r * HEX_SIZE*sqrt(3),
           hexPosition.y());

    QPolygonF hexagon(hexPoints);
    setPolygon(hexagon);
}

void TowerRangeAttack::setNewLastPoint()
{
    lastPoint.setX(hexPoints[hexPoints.length()-1].x());
    lastPoint.setY(hexPoints[hexPoints.length()-1].y());
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
    double addToX = lastPoint.x() - HEX_SIZE/2 - 12 - addedX;
    double addToY = lastPoint.y() + HEX_SIZE/2 + addedY;

    createAllPoints(QVector<unsigned short> {3,2,1}, addToX, addToY);
}

void TowerRangeAttack::createLeftDownElement(double addedX, double addedY)
{    
    double addToX = lastPoint.x() - 5 - addedX;
    double addToY = lastPoint.y() - HEX_SIZE - addedY;

    createAllPoints(QVector<unsigned short> {5,6,1}, addToX, addToY);
}

void TowerRangeAttack::createAllPoints(QVector<unsigned short> anglePoints, double addToX, double addToY)
{
    hexPoints << createPoint(anglePoints[0], addToX, addToY);
    hexPoints << createPoint(anglePoints[1], addToX, addToY);
    hexPoints << createPoint(anglePoints[2], addToX, addToY);
}

QPointF TowerRangeAttack::createPoint(unsigned short anglePoint, double addToX, double addToY)
{
    double angle_deg, angle_rad;

    angle_deg = 60 * anglePoint - 30;
    angle_rad = M_PI / 180 * angle_deg;
    return QPointF (x() - HEX_SIZE * cos(angle_rad) + addToX,
               y() - HEX_SIZE * sin(angle_rad) + addToY);
}
