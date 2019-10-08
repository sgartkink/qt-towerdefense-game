#include "game.h"

Game::Game()
{
    configureLayout();

    map->createAllHexesAndAddToScene();
    gridLayout->addWidget(map,0,0);
}

void Game::configureLayout()
{
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setColumnMinimumWidth(0,750);
    gridLayout->setColumnMinimumWidth(1,200);
    gridLayout->setRowMinimumHeight(0,580);
    gridLayout->setRowMinimumHeight(1,120);

    setLayout(gridLayout);
}

void Game::configureInterfaces()
{
    interfaceOnTheRightSide = new InterfaceOnRightSide();
    gridLayout->addWidget(interfaceOnTheRightSide,0,1);

    interfaceOnBottom = new InterfaceOnBottom();
    gridLayout->addWidget(interfaceOnBottom,1,0,1,2);
}

void Game::configurePathForEnemy()
{
    map->setPathForEnemy();
}

void Game::setAllConnects()
{
    interfaceOnTheRightSide->setAllConnects();
}

void Game::increaseLevelAndUpdateInterfaces()
{
    level++;
    interfaceOnBottom->updateLevel();
}
