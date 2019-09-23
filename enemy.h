#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#include <QLineF>
#include <QPen>
#include <QTimer>
#include <QtMath>

/**
 * TODO:
 * 1. the enemy's position is always in the middle of the hex
 * regardless of the hex size
 */

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    static int enemyCount;

    const int LENGTH_OF_MOVEMENT = 5;

    int nr;
    int hp = 10;
    QList<QPointF> pathPoints;
    int pathPoints_index = 1; //because pathPoints[0] is (0,0)
    QPointF destPoint;
    QTimer * moveTimer = new QTimer(this);
    QLineF lineToDestPoint;

    void rotateToPoint();
    void updateLine();
    void checkIfEnemyIsCloseEnoughToNextPoint();
    void setNewDestPointAndRotate();

private slots:
    void moveForward();

public:
    Enemy(QList<QPointF> pathPoints_);

    int getNr() { return nr; }
    int getHp() const { return hp; }

    void reduceHP(int reduction);
    void checkIfEnemyStillExists();
};

#endif // ENEMY_H
