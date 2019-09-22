#include "pathforenemy.h"

#include "game.h"
extern Game * game;

QPointF PathForEnemy::getHexCenter(int x, int y)
{
    return QPointF(getHexCenterX(x,y), getHexCenterY(x,y));
}

qreal PathForEnemy::getHexCenterX(int x, int y)
{
    return game->map->getHex(x,y)->x() + HEX_SIZE/2;
}

qreal PathForEnemy::getHexCenterY(int x, int y)
{
    return game->map->getHex(x,y)->y() + HEX_SIZE/2;
}

PathForEnemy::PathForEnemy()
{
    QPointF p0(0, 0);
    QPointF p1(getHexCenter(0,1));
    QPointF p2(getHexCenter(0,2));
    QPointF p3(getHexCenter(0,3));
    QPointF p4(getHexCenter(0,4));
    QPointF p5(getHexCenter(0,5));
    QPointF p6(getHexCenter(0,6));
    QPointF p7(getHexCenter(0,7));
    QPointF p8(getHexCenter(1,7));
    QPointF p9(getHexCenter(2,7));

    points.append(p0);
    points.append(p1);
    points.append(p2);
    points.append(p3);
    points.append(p4);
    points.append(p5);
    points.append(p6);
    points.append(p7);
    points.append(p8);
    points.append(p9);

    QLineF ln0 = QLineF(p0, p1);
    QLineF ln1 = QLineF(p1, p2);
    QLineF ln2 = QLineF(p2, p3);
    QLineF ln3 = QLineF(p3, p4);
    QLineF ln4 = QLineF(p4, p5);
    QLineF ln5 = QLineF(p5, p6);
    QLineF ln6 = QLineF(p6, p7);
    QLineF ln7 = QLineF(p7, p8);
    QLineF ln8 = QLineF(p8, p9);

    QGraphicsLineItem * l0 = new QGraphicsLineItem(ln0);
    QGraphicsLineItem * l1 = new QGraphicsLineItem(ln1);
    QGraphicsLineItem * l2 = new QGraphicsLineItem(ln2);
    QGraphicsLineItem * l3 = new QGraphicsLineItem(ln3);
    QGraphicsLineItem * l4 = new QGraphicsLineItem(ln4);
    QGraphicsLineItem * l5 = new QGraphicsLineItem(ln5);
    QGraphicsLineItem * l6 = new QGraphicsLineItem(ln6);
    QGraphicsLineItem * l7 = new QGraphicsLineItem(ln7);
    QGraphicsLineItem * l8 = new QGraphicsLineItem(ln8);

    QPen pen(Qt::white);
    l0->setPen(pen);
    l1->setPen(pen);
    l2->setPen(pen);
    l3->setPen(pen);
    l4->setPen(pen);
    l5->setPen(pen);
    l6->setPen(pen);
    l7->setPen(pen);
    l8->setPen(pen);

    game->map->getScene()->addItem(l0);
    game->map->getScene()->addItem(l1);
    game->map->getScene()->addItem(l2);
    game->map->getScene()->addItem(l3);
    game->map->getScene()->addItem(l4);
    game->map->getScene()->addItem(l5);
    game->map->getScene()->addItem(l6);
    game->map->getScene()->addItem(l7);
    game->map->getScene()->addItem(l8);
}
