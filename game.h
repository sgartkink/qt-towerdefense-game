#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>

#include "map.h"
#include "interfaceonbottom.h"
#include "interfaceonrightside.h"

class Game : public QWidget
{
private:
    void configureLayout();

public:
    QGridLayout * gridLayout = new QGridLayout;
    Map * map = new Map();
    InterfaceOnRightSide * interfaceOnTheRightSide = new InterfaceOnRightSide;
    InterfaceOnBottom * interfaceOnBottom = new InterfaceOnBottom;

    Game();

    void setAllConnects();
};

#endif // GAME_H
