#ifndef CHOSENTOWEREFFECT_H
#define CHOSENTOWEREFFECT_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include <QPen>

#include "global_consts.h"

/**
 * TODO:
 * 1. hex effect size and position is basing on the hex size
 */

class ChosenHexEffect : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
private:
    const qreal MAX_ELLIPSE_SIZE = 50;
    const qreal MAX_DIFFERENCE_STARTING_CURRENT_POS = 20;

    qreal currentEllipsePosition = HEX_EFFECT_STARTING_POSITION;
    qreal currentEllipseSize = HEX_EFFECT_STARTING_SIZE;

    QTimer * timerForChangeRect = new QTimer(this);

private slots:
    void changeRect();

public:
    ChosenHexEffect();
    ~ChosenHexEffect();
};

#endif // CHOSENTOWEREFFECT_H
