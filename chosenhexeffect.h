#ifndef CHOSENTOWEREFFECT_H
#define CHOSENTOWEREFFECT_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include <QPen>

#include "global_consts.h"

class ChosenHexEffect : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
private:
    const qreal MAX_ELLIPSE_SIZE = HEX_SIZE + HEX_SIZE/4;
    const qreal HEX_EFFECT_STARTING_SIZE = MAX_ELLIPSE_SIZE - HEX_SIZE;

    const qreal HEX_EFFECT_STARTING_POSITION = HEX_SIZE/2 - HEX_EFFECT_STARTING_SIZE/2;
    const qreal MIN_ELLIPSE_POS = HEX_EFFECT_STARTING_POSITION - HEX_SIZE/2;

    const qreal INCREASING_SPEED = 1;

    qreal currentEllipseSize = HEX_EFFECT_STARTING_SIZE;
    qreal currentEllipsePosition = HEX_EFFECT_STARTING_POSITION;

    QTimer * timerForChangeRect = new QTimer(this);

    void updateSize();
    void updatePos();

private slots:
    void changeRect();

public:
    ChosenHexEffect();
    ~ChosenHexEffect();
};

#endif // CHOSENTOWEREFFECT_H
