#include "enemy.h"

#include "game.h"
extern Game * game;

int Enemy::enemyCount = 0;

Enemy::Enemy()
    : pathPoints(game->map->getPathForEnemy())
{
    setRect(0, -ENEMY_SIZE/2, ENEMY_SIZE, ENEMY_SIZE);

    QBrush brush(ENEMY_COLOR);
    setBrush(brush);

    nr = enemyCount;
    enemyCount++;

    destPoint = pathPoints[pathPoints_index];
    rotateToPoint();

    game->map->getScene()->addItem(hpBarEnemyFrame);
    hpBarEnemyFrame->setPos(x() - ENEMY_SIZE/2, y()-10);

    game->map->getScene()->addItem(hpBarEnemyFill);
    hpBarEnemyFill->setPos(x() - ENEMY_SIZE/2, y()-10);

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

    setHPBarPosBasedOnRotation();

    checkIfEnemyIsCloseEnoughToNextPoint();
}

void Enemy::setHPBarPosBasedOnRotation()
{
    if (rotation() > -10 || rotation() < -350)
    {
        hpBarEnemyFrame->setPos(x() - ENEMY_SIZE/2, y() - ENEMY_SIZE);
        hpBarEnemyFill->setPos(x() - ENEMY_SIZE/2, y() - ENEMY_SIZE);
    }
    else if (rotation() < -50 && rotation() > -130)
    {
        hpBarEnemyFrame->setPos(x() - ENEMY_SIZE/2, y()-10 - HEX_SIZE/2);
        hpBarEnemyFill->setPos(x() - ENEMY_SIZE/2, y()-10 - HEX_SIZE/2);
    }
    else
    {
        hpBarEnemyFrame->setPos(x() - ENEMY_SIZE/2, y()-ENEMY_SIZE/2);
        hpBarEnemyFill->setPos(x() - ENEMY_SIZE/2, y()-ENEMY_SIZE/2);
    }
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

    if (checkIfPathIsOver())
        return;

    destPoint = pathPoints[pathPoints_index];
    rotateToPoint();
}

bool Enemy::checkIfPathIsOver()
{
    if (pathPoints_index >= pathPoints.size())
    {
        attackPlayer();
        game->map->getNewLevelEnemies()->decreaseEnemies();
        this->~Enemy();
        return true;
    }
    return false;
}

void Enemy::attackPlayer()
{
    game->player->decreaseHp(damage);
}

void Enemy::reduceHP(unsigned int reduction)
{
    hp -= reduction;

    if (hp > 0)
        hpBarEnemyFill->changeRect(hp);
    else
        deleteEnemy();
}

void Enemy::checkIfEnemyStillExists()
{
    if (hp <= 0)
        deleteEnemy();
}

void Enemy::deleteEnemy()
{
    moveTimer->stop();
    game->map->getScene()->removeItem(hpBarEnemyFrame);
    game->map->getScene()->removeItem(hpBarEnemyFill);
    game->map->getScene()->removeItem(this);
    game->map->getNewLevelEnemies()->decreaseEnemies();

    if (hp <= 0)
        game->player->increaseMoney(reward);
}
