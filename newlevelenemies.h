#ifndef NEWLEVELENEMIES_H
#define NEWLEVELENEMIES_H

#include <QObject>
#include <QVector>
#include <QTimer>

#include "enemy.h"

class NewLevelEnemies : public QObject
{
    Q_OBJECT
private:
    const unsigned short NR_ENEMIES_IN_VECTOR = 0;
    const unsigned short NR_FREQUENCY_CREATING_ENEMIES = 1;

    QTimer * timerCreateNewEnemy = new QTimer(this);
    unsigned int enemiesCount = 0;
    unsigned int enemiesLeft;
    bool isRunningLevel = false;
    QVector<QVector<unsigned int>> vectorEnemies;

    void createAllLevels();
    void checkIfAllEnemiesAreCreated();
    void stopCreatingNewEnemies();
    void checkIfAllEnemiesAreKilled();
    void endLevel();

public:
    NewLevelEnemies();

    unsigned int getEnemiesLeft() { return enemiesLeft; }
    bool getIsRunningLevel() { return isRunningLevel; }

    void decreaseEnemies();
    void updateQLCDNumberEnemiesLeft();

public slots:
    void startNewLevel();
    void createNewEnemy();
};

#endif // NEWLEVELENEMIES_H
