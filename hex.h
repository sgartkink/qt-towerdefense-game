#ifndef HEX_H
#define HEX_H

#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>
#include <QtMath>
#include <QtDebug>

#include "global_consts.h"
#include "tower.h"

class Hex : public QGraphicsPolygonItem
{
private:
    const int xOffset, xAxial, yCord, zCord;
    QBrush brush = QBrush(HEX_NORMAL_COLOR, Qt::SolidPattern);
    QPen pen = QPen(HEX_PEN_COLOR);
    Tower * tower = nullptr;
    bool isTower = false;
    bool inRangeChosenHexWithTower = false;

    inline int offsetToAxial(int x, int y) { return x - (y-(y&1))/2; }

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

public:
    Hex(int x, int y, QGraphicsItem * parent = nullptr);
    ~Hex() {}

    int getXOffset() const { return xOffset; }
    int getXAxial() const { return xAxial; }
    int getY() const { return yCord; }
    int getZ() const { return zCord; }
    unsigned int getTowerAttackRange() const { return tower->getAttackRange(); }
    bool hasTower() const { return isTower; }

    void setInRangeChosenHexWithTower(bool b) { inRangeChosenHexWithTower = b; }
    void setHasTower(bool t) { isTower = t; }
    void setTower(Tower * t) { tower = t; }

    void changeHexBrushAndUpdate(Qt::GlobalColor color);
};

#endif // HEX_H
