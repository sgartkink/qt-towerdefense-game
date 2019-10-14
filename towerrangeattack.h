#ifndef TOWERRANGEATTACK_H
#define TOWERRANGEATTACK_H

#include <QGraphicsPolygonItem>
#include <QtMath>
#include <QPen>

#include "towerrangeattackelement.h"
#include "global_consts.h"

class TowerRangeAttack : public QGraphicsPolygonItem
{
private:
    unsigned int range;
    QPointF lastPoint;
    QPen pen = QPen(Qt::red);
    QVector<QPointF> hexPoints;

    void setNewLastPoint();

    void createLeftUpElement(double addedX, double addedY);
    void createUpElement(double addedX, double addedY);
    void createRightUpElement(double addedX, double addedY);
    void createRightDownElement(double addedX, double addedY);
    void createDownElement(double addedX, double addedY);
    void createLeftDownElement(double addedX, double addedY);

    void createAllPoints(QVector<unsigned short> anglePoints, double addToX, double addToY);
    QPointF createPoint(unsigned short anglePoint, double addToX, double addToY);

public:
    TowerRangeAttack(unsigned int r, QPointF hexPosition);
};

#endif // TOWERRANGEATTACK_H
