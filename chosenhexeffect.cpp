#include "chosenhexeffect.h"

void ChosenHexEffect::changeRect()
{
    if (currentEllipseSize > MAX_ELLIPSE_SIZE)
        currentEllipseSize = HEX_EFFECT_STARTING_SIZE;
    else
        currentEllipseSize++;

    if (currentEllipsePosition < HEX_EFFECT_STARTING_POSITION - MAX_DIFFERENCE_STARTING_CURRENT_POS)
        currentEllipsePosition = HEX_EFFECT_STARTING_POSITION;
    else
        currentEllipsePosition -= 0.5;

    setRect(currentEllipsePosition, currentEllipsePosition, currentEllipseSize, currentEllipseSize);
}

ChosenHexEffect::ChosenHexEffect()
{
    QPen pen(EFFECT_PEN_COLOR);
    setPen(pen);

    connect(timerForChangeRect, SIGNAL(timeout()), this, SLOT(changeRect()));

    timerForChangeRect->start(50);
}

ChosenHexEffect::~ChosenHexEffect()
{
    timerForChangeRect->stop();
}
