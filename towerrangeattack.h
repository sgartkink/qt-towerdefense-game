#ifndef TOWERRANGEATTACK_H
#define TOWERRANGEATTACK_H

#include <QGraphicsPolygonItem>
#include <QtMath>
#include <QPen>

#include "global_consts.h"

class TowerRangeAttack : public QGraphicsPolygonItem
{
private:
    unsigned int range;
    QPointF lastPoint;
    QPointF hexPosition;
    QPen pen = QPen(Qt::red);
    QVector<QPointF> hexPoints_calc;
    QVector<QPointF> hexPoints_visible;

    void setNewLastPoint();

    void createLeftUpElement(double addedX, double addedY);
    void createUpElement(double addedX, double addedY);
    void createRightUpElement(double addedX, double addedY);
    void createRightDownElement(double addedX, double addedY);
    void createDownElement(double addedX, double addedY);
    void createLeftDownElement(double addedX, double addedY);

    void createAllPoints(QVector<unsigned short> anglePoints, double addToX, double addToY);
    void createPoint(unsigned short anglePoint, double addToX, double addToY);

public:
    TowerRangeAttack(unsigned int r, QPointF hexPosition_);
};

#endif // TOWERRANGEATTACK_H
