#include "enemy.h"

#include "game.h"
extern Game * game;

int Enemy::enemyCount = 0;

Enemy::Enemy(QList<QPointF> pathPoints_)
    : pathPoints(pathPoints_)
{
    setRect(0, -10, ENEMY_SIZE, ENEMY_SIZE);

    QBrush brush(ENEMY_COLOR);
    setBrush(brush);

    nr = enemyCount;
    enemyCount++;

    destPoint = pathPoints[pathPoints_index];
    rotateToPoint();

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveForward()));
    moveTimer->start(150);
}

void Enemy::moveForward()
{
    updateLine();

    double theta = rotation();

    double dy = LENGTH_OF_MOVEMENT * qSin(qDegreesToRadians(theta));
    double dx = LENGTH_OF_MOVEMENT * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

    checkIfEnemyIsCloseEnoughToNextPoint();
}

void Enemy::rotateToPoint()
{
    updateLine();
    setRotation(-1 * lineToDestPoint.angle());
}

void Enemy::updateLine()
{
    lineToDestPoint = QLineF(pos(), destPoint);
}

void Enemy::checkIfEnemyIsCloseEnoughToNextPoint()
{
    if (lineToDestPoint.length() < 5)
        setNewDestPointAndRotate();
}

void Enemy::setNewDestPointAndRotate()
{
    pathPoints_index++;
    if (pathPoints_index >= pathPoints.size())
        return;

    destPoint = pathPoints[pathPoints_index];
    rotateToPoint();
}

void Enemy::reduceHP(int reduction)
{
    hp -= reduction;

    checkIfEnemyStillExists();
}

void Enemy::checkIfEnemyStillExists()
{
    if (hp <= 0)
    {
        moveTimer->stop();
        disconnect(moveTimer, SIGNAL(timeout()), this, SLOT(moveForward()));
        game->map->getScene()->removeItem(this);
    }
}
