#include "interfaceonrightside.h"

#include "game.h"
extern Game * game;

InterfaceOnRightSide::InterfaceOnRightSide()
{
    addWidget(interfaceWaitForClickHex);
    addWidget(interfaceWithTowerOptions);
    addWidget(interfaceTowerDetails);
}

void InterfaceOnRightSide::setAllConnects()
{
    interfaceWithTowerOptions->setAllButtonConnects();
}
