#ifndef TOWERSQUAREOBJECT_H
#define TOWERSQUAREOBJECT_H

#include <QGraphicsRectItem>
#include <QPen>

#include "global_consts.h"

class TowerSquareObject : public QGraphicsRectItem
{
private:
    QPen pen;

public:
    TowerSquareObject(Qt::GlobalColor color);
};

#endif // TOWERSQUAREOBJECT_H
