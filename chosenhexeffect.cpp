#include "chosenhexeffect.h"

ChosenHexEffect::ChosenHexEffect()
{
    QPen pen(EFFECT_PEN_COLOR);
    setPen(pen);

    connect(timerForChangeRect, SIGNAL(timeout()), this, SLOT(changeRect()));
    timerForChangeRect->start(50);
}

void ChosenHexEffect::changeRect()
{
    updateSize();
    updatePos();

    setRect(currentEllipsePosition, currentEllipsePosition, currentEllipseSize, currentEllipseSize);
}

void ChosenHexEffect::updateSize()
{
    if (currentEllipseSize > MAX_ELLIPSE_SIZE)
        currentEllipseSize = HEX_EFFECT_STARTING_SIZE;
    else
        currentEllipseSize += INCREASING_SPEED;
}

void ChosenHexEffect::updatePos()
{
    if (currentEllipsePosition < MIN_ELLIPSE_POS)
        currentEllipsePosition = HEX_EFFECT_STARTING_POSITION;
    else
        currentEllipsePosition -= INCREASING_SPEED/2;
}

ChosenHexEffect::~ChosenHexEffect()
{
    timerForChangeRect->stop();
}
