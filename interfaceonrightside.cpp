#include "interfaceonrightside.h"

#include "game.h"
extern Game * game;

InterfaceOnRightSide::InterfaceOnRightSide()
{
    addWidget(widgetWaitForClickHex);
    addWidget(widgetWithTowerOptions);
    addWidget(widgetTowerDetails);
    addWidget(widgetEndGame);
}

void InterfaceOnRightSide::setAllConnects()
{
    widgetWithTowerOptions->setAllButtonConnects();
}
