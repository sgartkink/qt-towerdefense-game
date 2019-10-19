#include "bullet.h"

#include "game.h"
extern Game * game;

Bullet::Bullet(Qt::GlobalColor color, Enemy *e, unsigned int damage_)
    : aim(e), damage(damage_)
{   
    setRect(0, 0, BULLET_SIZE, BULLET_SIZE);

    QBrush brush(color, Qt::SolidPattern);
    setBrush(brush);

    QPen pen(color);
    setPen(pen);

    connect(timerForCheckingAim, SIGNAL(timeout()), this, SLOT(checkExistenceOfAim()));
    timerForCheckingAim->start(50);
}

void Bullet::checkExistenceOfAim()
{
    if (aim->scene())
        moveBulletTowardsAim();
    else
    {
        timerForCheckingAim->stop();
        delete this;
    }
}

void Bullet::moveBulletTowardsAim()
{
    rotateToAim();

    double theta = rotation();

    double dx = LENGTH_OF_MOVEMENT * qCos(qDegreesToRadians(theta));
    double dy = LENGTH_OF_MOVEMENT * qSin(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

    checkIfBulletIsCloseEnoughAim();
}

void Bullet::rotateToAim()
{
    updateLine();
    setRotation(-1 * lineFromBulletToAim.angle());
}

void Bullet::updateLine()
{
    lineFromBulletToAim = QLineF(pos(), QPointF(aim->pos().x() + ENEMY_SIZE/2, aim->pos().y() + ENEMY_SIZE/2));
}

void Bullet::checkIfBulletIsCloseEnoughAim()
{
    if (lineFromBulletToAim.length() < LENGTH_OF_MOVEMENT)
    {
        aim->reduceHP(damage);
        timerForCheckingAim->stop();
        delete this;
    }
}
