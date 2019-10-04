#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#include <QLineF>
#include <QPen>
#include <QTimer>
#include <QtMath>

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    static int enemyCount;

    const unsigned int LENGTH_OF_MOVEMENT = 5;
    const unsigned int reward = 10;
    const unsigned int damage = 1;
    const QList<QPointF> pathPoints;

    int nr;
    int hp = 10;
    int pathPoints_index = 1; //because pathPoints[0] is (0,0)
    QPointF destPoint;
    QTimer * moveTimer = new QTimer(this);
    QLineF lineToDestPoint;

    void rotateToPoint();
    void updateLine();
    void checkIfEnemyIsCloseEnoughToNextPoint();
    void setNewDestPointAndRotate();
    bool checkIfPathIsOver();
    void attackPlayer();

private slots:
    void moveForward();

public:
    Enemy();
    ~Enemy();

    int getNr() { return nr; }
    int getHp() const { return hp; }
    unsigned int getReward() const { return reward; }

    void reduceHP(unsigned int reduction);
    void checkIfEnemyStillExists();
};

#endif // ENEMY_H
