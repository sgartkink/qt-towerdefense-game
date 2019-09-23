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
    QGridLayout * gridLayout;
    Map * map;
    InterfaceOnRightSide * interfaceOnTheRightSide;
    InterfaceOnBottom * interfaceOnBottom;

    Game();

    void setAllConnects();
};

#endif // GAME_H
