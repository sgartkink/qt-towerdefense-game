#ifndef PATHFORENEMY_H
#define PATHFORENEMY_H

#include <QPointF>
#include <QList>

class PathForEnemy
{
private:
    QList<QPointF> points;

    QPointF getHexCenter(int x, int y);
    qreal getHexCenterX(int x, int y);
    qreal getHexCenterY(int x, int y);

public:
    PathForEnemy();

    QList<QPointF> getPoints() { return points; }
};

#endif // PATHFORENEMY_H
