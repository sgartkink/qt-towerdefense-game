#include "hpbarenemyfill.h"

HPBarEnemyFill::HPBarEnemyFill(int MAX_HP_)
    : MAX_HP(MAX_HP_)
{
    brush.setColor(Qt::green);
    setBrush(brush);

    setRect(0,0,30,10);
}

void HPBarEnemyFill::changeRect(int currentHP)
{
    qreal divideCurrentMax = currentHP*100/MAX_HP;
    if (divideCurrentMax < 25)
        brush.setColor(Qt::red);
    else if (divideCurrentMax < 50)
        brush.setColor(Qt::yellow);

    setBrush(brush);

    setRect(0,0,30*divideCurrentMax/100,10);
}
