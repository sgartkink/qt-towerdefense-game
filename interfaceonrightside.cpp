#include "interfaceonrightside.h"
#include "game.h"

extern Game * game;

void InterfaceOnRightSide::createButton(QPushButton *button)
{
    button->setVisible(false);
    vLayout->addWidget(button);
}

void InterfaceOnRightSide::changeButtonsVisible(bool v)
{
    buttonBlueTower->setVisible(v);
    buttonGreenTower->setVisible(v);
    buttonDarkCyanTower->setVisible(v);
    buttonWhiteTower->setVisible(v);
    buttonYellowTower->setVisible(v);
}

InterfaceOnRightSide::InterfaceOnRightSide()
{
    vLayout = new QVBoxLayout(this);
    vLayout->setMargin(0);
    vLayout->setSpacing(0);

    setLayout(vLayout);

    text = new QLabel("Click on hex");
    text->setMargin(0);
    text->setMaximumHeight(10);
    vLayout->addWidget(text);

    createButton(buttonBlueTower);
    createButton(buttonGreenTower);
    createButton(buttonDarkCyanTower);
    createButton(buttonWhiteTower);
    createButton(buttonYellowTower);
}

void InterfaceOnRightSide::showTowerButtons()
{
    changeButtonsVisible(true);
}

void InterfaceOnRightSide::hideTowerButtons()
{
    changeButtonsVisible(false);
}

void InterfaceOnRightSide::setAllConnects()
{
    connect(buttonBlueTower, &QPushButton::clicked, [](){ game->map->createTower(BLUE_TOWER_NR); });
    connect(buttonGreenTower, &QPushButton::clicked, [](){ game->map->createTower(GREEN_TOWER_NR); });
    connect(buttonDarkCyanTower, &QPushButton::clicked, [](){ game->map->createTower(DARKCYAN_TOWER_NR); });
    connect(buttonWhiteTower, &QPushButton::clicked, [](){ game->map->createTower(WHITE_TOWER_NR); });
    connect(buttonYellowTower, &QPushButton::clicked, [](){ game->map->createTower(YELLOW_TOWER_NR); });
}
