#ifndef TOWERRANGEATTACK_H
#define TOWERRANGEATTACK_H

#include <QGraphicsPolygonItem>
#include <QtMath>

#include "global_consts.h"

class TowerRangeAttack : public QGraphicsPolygonItem
{
private:
    unsigned int range;
public:
    TowerRangeAttack(unsigned int r, double x_, double y_);
};

#endif // TOWERRANGEATTACK_H
