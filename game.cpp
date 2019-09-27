#include "game.h"

Game::Game()
{
    configureLayout();

    map = new Map();
    map->createAllHexesAndAddToScene();
    gridLayout->addWidget(map,0,0);

    interfaceOnTheRightSide = new InterfaceOnRightSide();
    gridLayout->addWidget(interfaceOnTheRightSide,0,1);

    interfaceOnBottom = new InterfaceOnBottom();
    gridLayout->addWidget(interfaceOnBottom,1,0,1,2);

    setLayout(gridLayout);
}

void Game::configureLayout()
{
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setColumnMinimumWidth(0,750);
    gridLayout->setColumnMinimumWidth(1,200);
    gridLayout->setRowMinimumHeight(0,580);
    gridLayout->setRowMinimumHeight(1,120);
}

void Game::setAllConnects()
{
    interfaceOnTheRightSide->setAllConnects();
}
