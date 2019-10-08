#include "towersquareobject.h"

TowerSquareObject::TowerSquareObject(Qt::GlobalColor color)
{
    pen = QPen(color);
    setPen(pen);
}
