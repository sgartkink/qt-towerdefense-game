#include "interfacewithtoweroptions.h"

#include "game.h"
extern Game * game;

InterfaceWithTowerOptions::InterfaceWithTowerOptions(QWidget *parent) : QWidget(parent)
{
    setLayout(vLayout);

    vLayout->addWidget(widgetBlueTowerOptions);
    vLayout->addWidget(widgetGreenTowerOptions);
    vLayout->addWidget(widgetWhiteTowerOptions);
    vLayout->addWidget(widgetYellowTowerOptions);
    vLayout->addWidget(widgetDarkCyanTowerOptions);
}

void InterfaceWithTowerOptions::setAllButtonConnects()
{
    connect(widgetBlueTowerOptions->getButton(), &QPushButton::clicked, [](){ game->map->createTower(BLUE_TOWER_NR); });
    connect(widgetGreenTowerOptions->getButton(), &QPushButton::clicked, [](){ game->map->createTower(GREEN_TOWER_NR); });
    connect(widgetWhiteTowerOptions->getButton(), &QPushButton::clicked, [](){ game->map->createTower(WHITE_TOWER_NR); });
    connect(widgetYellowTowerOptions->getButton(), &QPushButton::clicked, [](){ game->map->createTower(YELLOW_TOWER_NR); });
    connect(widgetDarkCyanTowerOptions->getButton(), &QPushButton::clicked, [](){ game->map->createTower(DARKCYAN_TOWER_NR); });

    connect(widgetBlueTowerOptions->getButton(), SIGNAL(clicked()), this, SLOT(updateButtons()));
    connect(widgetGreenTowerOptions->getButton(), SIGNAL(clicked()), this, SLOT(updateButtons()));
    connect(widgetWhiteTowerOptions->getButton(), SIGNAL(clicked()), this, SLOT(updateButtons()));
    connect(widgetYellowTowerOptions->getButton(), SIGNAL(clicked()), this, SLOT(updateButtons()));
    connect(widgetDarkCyanTowerOptions->getButton(), SIGNAL(clicked()), this, SLOT(updateButtons()));
}

void InterfaceWithTowerOptions::updateButtons()
{
    widgetBlueTowerOptions->updateButton();
    widgetGreenTowerOptions->updateButton();
    widgetWhiteTowerOptions->updateButton();
    widgetYellowTowerOptions->updateButton();
    widgetDarkCyanTowerOptions->updateButton();
}
