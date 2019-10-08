#include "interfaceonrightside.h"

#include "game.h"
extern Game * game;

InterfaceOnRightSide::InterfaceOnRightSide()
{
    addWidget(widgetWaitForClickHex);
    addWidget(widgetWithTowerOptions);
    addWidget(widgetTowerDetails);
}

void InterfaceOnRightSide::setAllConnects()
{
    widgetWithTowerOptions->setAllButtonConnects();
}
