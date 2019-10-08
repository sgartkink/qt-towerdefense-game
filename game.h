#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGridLayout>

#include "map.h"
#include "interfaceonbottom.h"
#include "interfaceonrightside.h"
#include "player.h"

class Game : public QWidget
{
private:
    unsigned int level = 1;

    void configureLayout();

public:
    Game();

    QGridLayout * gridLayout = new QGridLayout();
    Map * map = new Map();
    Player * player = new Player();
    InterfaceOnRightSide * interfaceOnTheRightSide;
    InterfaceOnBottom * interfaceOnBottom;

    unsigned int getLevel() { return level; }
    void increaseLevelAndUpdateInterfaces();

    void setAllConnects();
    void configureInterfaces();
    void configurePathForEnemy();
};

#endif // GAME_H
