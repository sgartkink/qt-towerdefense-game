#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#include <QLineF>
#include <QPen>
#include <QTimer>
#include <QtMath>

#include "hpbarenemyframe.h"
#include "hpbarenemyfill.h"

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    static int enemyCount;

    const unsigned int LENGTH_OF_MOVEMENT = 5;
    const unsigned int reward = 10;
    const unsigned short damage = 1;
    const QList<QPointF> pathPoints;

    int nr;
    int hp = 20;
    int pathPoints_index = 1; //because pathPoints[0] is (0,0)
    HPBarEnemyFrame * hpBarEnemyFrame = new HPBarEnemyFrame();
    HPBarEnemyFill * hpBarEnemyFill = new HPBarEnemyFill(hp);
    QTimer * moveTimer = new QTimer(this);
    QPointF destPoint;
    QLineF lineToDestPoint;

    void setHPBarPosBasedOnRotation();
    void rotateToPoint();
    void updateLine();
    void checkIfEnemyIsCloseEnoughToNextPoint();
    void setNewDestPointAndRotate();
    bool checkIfPathIsOver();
    void attackPlayer();
    void checkIfEnemyStillExists();

private slots:
    void moveForward();

public:
    Enemy();
    ~Enemy();

    int getNr() { return nr; }
    int getHp() const { return hp; }

    void reduceHP(unsigned int reduction);
};

#endif // ENEMY_H
