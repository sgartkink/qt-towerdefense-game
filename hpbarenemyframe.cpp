#include "hpbarenemyframe.h"

#include "game.h"
extern Game * game;

HPBarEnemyFrame::HPBarEnemyFrame()
{
    setRect(0,0,30,10);

    QPen pen(Qt::black);
    setPen(pen);
}
