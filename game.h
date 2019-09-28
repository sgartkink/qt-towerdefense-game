#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>

#include "map.h"
#include "interfaceonbottom.h"
#include "interfaceonrightside.h"
#include "player.h"

class Game : public QWidget
{
private:
    void configureLayout();

public:
    QGridLayout * gridLayout = new QGridLayout();
    Map * map = new Map();
    Player * player = new Player();
    InterfaceOnRightSide * interfaceOnTheRightSide;
    InterfaceOnBottom * interfaceOnBottom;

    Game();

    void setAllConnects();
    void configureInterfaces();
};

#endif // GAME_H
