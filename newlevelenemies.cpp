#include "newlevelenemies.h"
#include <QtDebug>

#include "game.h"
extern Game * game;

NewLevelEnemies::NewLevelEnemies()
{
    vectorEnemies.resize(10);

    createAllLevels();
}

void NewLevelEnemies::createAllLevels()
{
    vectorEnemies[0].push_back(100); //enemies
    vectorEnemies[0].push_back(150); //frequency

    vectorEnemies[1].push_back(15);
    vectorEnemies[1].push_back(500);
}

void NewLevelEnemies::startNewLevel()
{
    enemiesLeft = vectorEnemies[game->getLevel()-1][NR_ENEMIES_IN_VECTOR];
    enemiesCount = enemiesLeft;

    connect(timerCreateNewEnemy, SIGNAL(timeout()), this, SLOT(createNewEnemy()));
    timerCreateNewEnemy->start(vectorEnemies[game->getLevel()-1][NR_FREQUENCY_CREATING_ENEMIES]);

    game->interfaceOnBottom->setButtonStartGameEnabled(false);
    game->map->startCollisionTimer();
    updateQLCDNumberEnemiesLeft();
}

void NewLevelEnemies::createNewEnemy()
{
    Enemy * enemy = new Enemy();
    game->map->getScene()->addItem(enemy);

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
    game->increaseLevelAndUpdateInterfaces();
    game->map->stopCollistionTimer();
}
