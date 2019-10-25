#include "newlevelenemies.h"
#include <QtDebug>

#include "game.h"
extern Game * game;

NewLevelEnemies::NewLevelEnemies()
{
    vectorEnemiesAmount.resize(MAX_LEVELS);

    createAllLevels();
}

void NewLevelEnemies::createAllLevels()
{
    vectorEnemiesAmount[0].push_back(2); //enemies
    vectorEnemiesAmount[0].push_back(250); //frequency

    vectorEnemiesAmount[1].push_back(2);
    vectorEnemiesAmount[1].push_back(250);
}

void NewLevelEnemies::startNewLevel()
{
    enemiesLeft = vectorEnemiesAmount[game->getLevel()-1][NR_ENEMIES_IN_VECTOR];
    enemiesCount = enemiesLeft;
    vectorEnemiesOnMap.resize(0);

    connect(timerCreateNewEnemy, SIGNAL(timeout()), this, SLOT(createNewEnemy()));
    timerCreateNewEnemy->start(vectorEnemiesAmount[game->getLevel()-1][NR_FREQUENCY_CREATING_ENEMIES]);

    game->interfaceOnBottom->setButtonStartGameEnabled(false);
    game->map->startCollisionTimer();
    updateQLCDNumberEnemiesLeft();
}

void NewLevelEnemies::createNewEnemy()
{
    Enemy * enemy = new Enemy();
    game->map->getScene()->addItem(enemy);
    vectorEnemiesOnMap.push_back(enemy);

    enemiesCount--;
    checkIfAllEnemiesAreCreated();
}

void NewLevelEnemies::checkIfAllEnemiesAreCreated()
{
    if (enemiesCount == 0)
        stopCreatingNewEnemies();
}

void NewLevelEnemies::stopCreatingNewEnemies()
{
    timerCreateNewEnemy->stop();
    disconnect(timerCreateNewEnemy, SIGNAL(timeout()), this, SLOT(createNewEnemy()));
}

void NewLevelEnemies::decreaseEnemies()
{
    enemiesLeft--;

    updateQLCDNumberEnemiesLeft();

    checkIfAllEnemiesAreKilled();
}

void NewLevelEnemies::updateQLCDNumberEnemiesLeft()
{
    game->interfaceOnBottom->updateEnemiesLeft();
}

void NewLevelEnemies::checkIfAllEnemiesAreKilled()
{
    if (enemiesLeft == 0)
        endLevel();
}

void NewLevelEnemies::endLevel()
{
    game->interfaceOnBottom->setButtonStartGameEnabled(true);
    game->map->stopCollistionTimer();

    vectorEnemiesOnMap[0]->resetEnemyCount();
    for (auto it = vectorEnemiesOnMap.begin(); it != vectorEnemiesOnMap.end(); ++it)
        delete (*it);
    vectorEnemiesOnMap.resize(0);

    if (game->getLevel() == MAX_LEVELS)
    {
        game->interfaceOnTheRightSide->getWidgetEndGame()->setIfPlayerWon(true);
        game->interfaceOnBottom->setButtonStartGameEnabled(false);
        game->interfaceOnTheRightSide->setWidget(WIDGET_END_GAME_NR);
        isGame = false;
    }
    else
        game->increaseLevelAndUpdateInterfaces();
}
