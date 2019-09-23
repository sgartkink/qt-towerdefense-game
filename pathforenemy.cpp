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
    QPointF p10(getHexCenter(2,6));
    QPointF p11(getHexCenter(2,5));
    QPointF p12(getHexCenter(2,4));
    QPointF p13(getHexCenter(2,3));
    QPointF p14(getHexCenter(2,2));
    QPointF p15(getHexCenter(2,1));
    QPointF p16(getHexCenter(2,0));
    QPointF p17(getHexCenter(3,0));
    QPointF p18(getHexCenter(4,0));
    QPointF p19(getHexCenter(4,1));
    QPointF p20(getHexCenter(4,2));
    QPointF p21(getHexCenter(4,3));
    QPointF p22(getHexCenter(4,4));
    QPointF p23(getHexCenter(4,5));
    QPointF p24(getHexCenter(4,6));
    QPointF p25(getHexCenter(4,7));
    QPointF p26(getHexCenter(5,7));
    QPointF p27(getHexCenter(6,7));
    QPointF p28(getHexCenter(6,6));
    QPointF p29(getHexCenter(6,5));
    QPointF p30(getHexCenter(6,4));
    QPointF p31(getHexCenter(6,3));
    QPointF p32(getHexCenter(6,2));
    QPointF p33(getHexCenter(6,1));
    QPointF p34(getHexCenter(6,0));
    QPointF p35(getHexCenter(7,0));

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
    points.append(p10);
    points.append(p11);
    points.append(p12);
    points.append(p13);
    points.append(p14);
    points.append(p15);
    points.append(p16);
    points.append(p17);
    points.append(p18);
    points.append(p19);
    points.append(p20);
    points.append(p21);
    points.append(p22);
    points.append(p23);
    points.append(p24);
    points.append(p25);
    points.append(p26);
    points.append(p27);
    points.append(p28);
    points.append(p29);
    points.append(p30);
    points.append(p31);
    points.append(p32);
    points.append(p33);
    points.append(p34);
    points.append(p35);

    QLineF ln0 = QLineF(p0, p1);
    QLineF ln1 = QLineF(p1, p2);
    QLineF ln2 = QLineF(p2, p3);
    QLineF ln3 = QLineF(p3, p4);
    QLineF ln4 = QLineF(p4, p5);
    QLineF ln5 = QLineF(p5, p6);
    QLineF ln6 = QLineF(p6, p7);
    QLineF ln7 = QLineF(p7, p8);
    QLineF ln8 = QLineF(p8, p9);
    QLineF ln9 = QLineF(p9, p10);
    QLineF ln10 = QLineF(p10, p11);
    QLineF ln11 = QLineF(p11, p12);
    QLineF ln12 = QLineF(p12, p13);
    QLineF ln13 = QLineF(p13, p14);
    QLineF ln14 = QLineF(p14, p15);
    QLineF ln15 = QLineF(p15, p16);
    QLineF ln16 = QLineF(p16, p17);
    QLineF ln17 = QLineF(p17, p18);
    QLineF ln18 = QLineF(p18, p19);
    QLineF ln19 = QLineF(p19, p20);
    QLineF ln20 = QLineF(p20, p21);
    QLineF ln21 = QLineF(p21, p22);
    QLineF ln22 = QLineF(p22, p23);
    QLineF ln23 = QLineF(p23, p24);
    QLineF ln24 = QLineF(p24, p25);
    QLineF ln25 = QLineF(p25, p26);
    QLineF ln26 = QLineF(p26, p27);
    QLineF ln27 = QLineF(p27, p28);
    QLineF ln28 = QLineF(p28, p29);
    QLineF ln29 = QLineF(p29, p30);
    QLineF ln30 = QLineF(p30, p31);
    QLineF ln31 = QLineF(p31, p32);
    QLineF ln32 = QLineF(p32, p33);
    QLineF ln33 = QLineF(p33, p34);
    QLineF ln34 = QLineF(p34, p35);


    QGraphicsLineItem * l0 = new QGraphicsLineItem(ln0);
    QGraphicsLineItem * l1 = new QGraphicsLineItem(ln1);
    QGraphicsLineItem * l2 = new QGraphicsLineItem(ln2);
    QGraphicsLineItem * l3 = new QGraphicsLineItem(ln3);
    QGraphicsLineItem * l4 = new QGraphicsLineItem(ln4);
    QGraphicsLineItem * l5 = new QGraphicsLineItem(ln5);
    QGraphicsLineItem * l6 = new QGraphicsLineItem(ln6);
    QGraphicsLineItem * l7 = new QGraphicsLineItem(ln7);
    QGraphicsLineItem * l8 = new QGraphicsLineItem(ln8);
    QGraphicsLineItem * l9 = new QGraphicsLineItem(ln9);
    QGraphicsLineItem * l10 = new QGraphicsLineItem(ln10);
    QGraphicsLineItem * l11 = new QGraphicsLineItem(ln11);
    QGraphicsLineItem * l12 = new QGraphicsLineItem(ln12);
    QGraphicsLineItem * l13 = new QGraphicsLineItem(ln13);
    QGraphicsLineItem * l14 = new QGraphicsLineItem(ln14);
    QGraphicsLineItem * l15 = new QGraphicsLineItem(ln15);
    QGraphicsLineItem * l16 = new QGraphicsLineItem(ln16);
    QGraphicsLineItem * l17 = new QGraphicsLineItem(ln17);
    QGraphicsLineItem * l18 = new QGraphicsLineItem(ln18);
    QGraphicsLineItem * l19 = new QGraphicsLineItem(ln19);
    QGraphicsLineItem * l20 = new QGraphicsLineItem(ln20);
    QGraphicsLineItem * l21 = new QGraphicsLineItem(ln21);
    QGraphicsLineItem * l22 = new QGraphicsLineItem(ln22);
    QGraphicsLineItem * l23 = new QGraphicsLineItem(ln23);
    QGraphicsLineItem * l24 = new QGraphicsLineItem(ln24);
    QGraphicsLineItem * l25 = new QGraphicsLineItem(ln25);
    QGraphicsLineItem * l26 = new QGraphicsLineItem(ln26);
    QGraphicsLineItem * l27 = new QGraphicsLineItem(ln27);
    QGraphicsLineItem * l28 = new QGraphicsLineItem(ln28);
    QGraphicsLineItem * l29 = new QGraphicsLineItem(ln29);
    QGraphicsLineItem * l30 = new QGraphicsLineItem(ln30);
    QGraphicsLineItem * l31 = new QGraphicsLineItem(ln31);
    QGraphicsLineItem * l32 = new QGraphicsLineItem(ln32);
    QGraphicsLineItem * l33 = new QGraphicsLineItem(ln33);
    QGraphicsLineItem * l34 = new QGraphicsLineItem(ln34);

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
    l9->setPen(pen);
    l10->setPen(pen);
    l11->setPen(pen);
    l12->setPen(pen);
    l13->setPen(pen);
    l14->setPen(pen);
    l15->setPen(pen);
    l16->setPen(pen);
    l17->setPen(pen);
    l18->setPen(pen);
    l19->setPen(pen);
    l20->setPen(pen);
    l21->setPen(pen);
    l22->setPen(pen);
    l23->setPen(pen);
    l24->setPen(pen);
    l25->setPen(pen);
    l26->setPen(pen);
    l27->setPen(pen);
    l28->setPen(pen);
    l29->setPen(pen);
    l30->setPen(pen);
    l31->setPen(pen);
    l32->setPen(pen);
    l33->setPen(pen);
    l34->setPen(pen);

    game->map->getScene()->addItem(l0);
    game->map->getScene()->addItem(l1);
    game->map->getScene()->addItem(l2);
    game->map->getScene()->addItem(l3);
    game->map->getScene()->addItem(l4);
    game->map->getScene()->addItem(l5);
    game->map->getScene()->addItem(l6);
    game->map->getScene()->addItem(l7);
    game->map->getScene()->addItem(l8);
    game->map->getScene()->addItem(l9);
    game->map->getScene()->addItem(l10);
    game->map->getScene()->addItem(l11);
    game->map->getScene()->addItem(l12);
    game->map->getScene()->addItem(l13);
    game->map->getScene()->addItem(l14);
    game->map->getScene()->addItem(l15);
    game->map->getScene()->addItem(l16);
    game->map->getScene()->addItem(l17);
    game->map->getScene()->addItem(l18);
    game->map->getScene()->addItem(l19);
    game->map->getScene()->addItem(l20);
    game->map->getScene()->addItem(l21);
    game->map->getScene()->addItem(l22);
    game->map->getScene()->addItem(l23);
    game->map->getScene()->addItem(l24);
    game->map->getScene()->addItem(l25);
    game->map->getScene()->addItem(l26);
    game->map->getScene()->addItem(l27);
    game->map->getScene()->addItem(l28);
    game->map->getScene()->addItem(l29);
    game->map->getScene()->addItem(l30);
    game->map->getScene()->addItem(l31);
    game->map->getScene()->addItem(l32);
    game->map->getScene()->addItem(l33);
    game->map->getScene()->addItem(l34);
}
