#include "bullet.h"

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
        delete this;
}

void Bullet::moveBulletTowardsAim()
{
    rotateToAim();

    double theta = rotation();

    double dy = LENGTH_OF_MOVEMENT * qSin(qDegreesToRadians(theta));
    double dx = LENGTH_OF_MOVEMENT * qCos(qDegreesToRadians(theta));

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
    lineFromBulletToAim = QLineF(pos(), aim->pos());
}

void Bullet::checkIfBulletIsCloseEnoughAim()
{
    if (lineFromBulletToAim.length() < 10)
    {
        aim->reduceHP(damage);
        timerForCheckingAim->stop();
        delete this;
    }
}
