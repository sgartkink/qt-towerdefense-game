#ifndef NEWLEVELENEMIES_H
#define NEWLEVELENEMIES_H

#include <QVector>
#include <QObject>
#include <QTimer>

#include "enemy.h"

class NewLevelEnemies : public QObject
{
    Q_OBJECT
private:
    const unsigned short NR_ENEMIES_IN_VECTOR = 0;
    const unsigned short NR_FREQUENCY_CREATING_ENEMIES = 1;

    QVector<QVector<unsigned int>> vectorEnemies;
    QTimer * timerCreateNewEnemy = new QTimer(this);
    unsigned int enemiesLeft;
    unsigned int enemiesCount = 0;

    void createAllLevels();
    void checkIfAllEnemiesAreCreated();
    void stopCreatingNewEnemies();

public:
    NewLevelEnemies();

    unsigned int getEnemiesLeft() { return enemiesLeft; }

    void decreaseEnemies();
    void updateQLCDNumberEnemiesLeft();

public slots:
    void startNewLevel();
    void createNewEnemy();
};

#endif // NEWLEVELENEMIES_H
