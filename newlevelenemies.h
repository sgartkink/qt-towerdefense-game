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
    const unsigned short MAX_LEVELS = 2;

    const unsigned short NR_ENEMIES_IN_VECTOR = 0;
    const unsigned short NR_FREQUENCY_CREATING_ENEMIES = 1;

    QTimer * timerCreateNewEnemy = new QTimer(this);
    unsigned int enemiesCount = 0;
    unsigned int enemiesLeft;
    QVector<QVector<unsigned int>> vectorEnemiesAmount;
    QVector<Enemy *> vectorEnemiesOnMap;
    bool isGame = true;

    void createAllLevels();
    void checkIfAllEnemiesAreCreated();
    void stopCreatingNewEnemies();
    void checkIfAllEnemiesAreKilled();
    void endLevel();

public:
    NewLevelEnemies();

    unsigned int getEnemiesLeft() { return enemiesLeft; }
    unsigned int getMAX_LEVELS() const { return MAX_LEVELS; }
    bool getIsGame() { return isGame; }

    void decreaseEnemies();
    void updateQLCDNumberEnemiesLeft();
    void setIsGameTrue() { isGame = true; }

public slots:
    void startNewLevel();
    void createNewEnemy();
};

#endif // NEWLEVELENEMIES_H
