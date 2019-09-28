#include "towerrangeattack.h"
#include <QPen>
#include <QPen>
#include <QtDebug>
TowerRangeAttack::TowerRangeAttack(unsigned int r, double x_, double y_)
    : range(r)
{    
    QVector<QPointF> hexPoints;

    QPen pen(Qt::red);
    double angle_deg, angle_rad;
    for (unsigned int i = 0; i < range; i++)
    {
        angle_deg = 60 * 1 - 30;
        angle_rad = M_PI / 180 * angle_deg;
        QPointF p0(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2,
                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*i*2/2 - HEX_SIZE/2*i);
        hexPoints << p0;
        angle_deg = 60 * 2 - 30;
        angle_rad = M_PI / 180 * angle_deg;
        QPointF p1(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2,
                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*i*2/2 - HEX_SIZE/2*i);
        hexPoints << p1;
        angle_deg = 60 * 2 - 30;
        angle_rad = M_PI / 180 * angle_deg;
        QPointF p2(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2,
                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*(i+1) - HEX_SIZE/2*i);
        hexPoints << p2;
        QLineF ln1 = QLineF(p0,p1);
        QLineF ln2 = QLineF(p1,p2);
        QGraphicsLineItem * l1 = new QGraphicsLineItem(ln1);
        QGraphicsLineItem * l2 = new QGraphicsLineItem(ln2);
        l1->setPen(pen);
        l2->setPen(pen);
    }

//    unsigned int i = range;
//    for (unsigned int j = 0; j < range+1; j++)
//    {
//        angle_deg = 60 * 1 - 30;
//        angle_rad = M_PI / 180 * angle_deg;
//        QPointF p0(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2 + HEX_SIZE*sqrt(3)*j,
//                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*i*2/2 - HEX_SIZE/2*i);
//        hexPoints << p0;
//        angle_deg = 60 * 2 - 30;
//        angle_rad = M_PI / 180 * angle_deg;
//        QPointF p1(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2 + HEX_SIZE*sqrt(3)*j,
//                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*i*2/2 - HEX_SIZE/2*i);
//        hexPoints << p1;
//        angle_deg = 60 * 4 - 30;
//        angle_rad = M_PI / 180 * angle_deg;
//        QPointF p2(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2 + HEX_SIZE*sqrt(3)*j,
//                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*(i+1) - HEX_SIZE/2*i);
//        hexPoints << p2;
//        QLineF ln1 = QLineF(p0,p1);
//        QLineF ln2 = QLineF(p1,p2);
//        QGraphicsLineItem * l1 = new QGraphicsLineItem(ln1);
//        QGraphicsLineItem * l2 = new QGraphicsLineItem(ln2);
//        l1->setPen(pen);
//        l2->setPen(pen);
//    }

//    for (int i = range-1, j = range+1; i >= 0; i--, j++)
//    {
//        angle_deg = 60 * 2 - 30;
//        angle_rad = M_PI / 180 * a + HEX_SIZE/2 - HEX_SIZE*i*2/2 - HEX_SIZE/2*i)ngle_deg;
//        QPointF p0(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2 + HEX_SIZE*sqrt(3)*j,
//                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*(i+1) - HEX_SIZE/2*i);
//        hexPoints << p0;
//        angle_deg = 60 * 2 - 30;
//        angle_rad = M_PI / 180 * angle_deg;
//        QPointF p1(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2 + HEX_SIZE*sqrt(3)*j,
//                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*i*2/2 - HEX_SIZE/2*i);
//        hexPoints << p1;
//        angle_deg = 60 * 3 - 30;
//        angle_rad = M_PI / 180 * angle_deg;
//        QPointF p2(x_ - HEX_SIZE * cos(angle_rad) + HEX_SIZE/2 - HEX_SIZE*sqrt(3)*range + HEX_SIZE*sqrt(3)*i/2 + HEX_SIZE*sqrt(3)*j,
//                   y_ - HEX_SIZE * sin(angle_rad) + HEX_SIZE/2 - HEX_SIZE*i*2/2 - HEX_SIZE/2*i);
//        hexPoints << p2;
//        QLineF ln1 = QLineF(p0,p1);
//        QLineF ln2 = QLineF(p1,p2);
//        QGraphicsLineItem * l1 = new QGraphicsLineItem(ln1);
//        QGraphicsLineItem * l2 = new QGraphicsLineItem(ln2);
//        l1->setPen(pen);
//        l2->setPen(pen);
//    }

    setPen(pen);
    QPolygonF hexagon(hexPoints);
    setPolygon(hexagon);
}
