#include "interfaceonbottom.h"

#include "game.h"
extern Game * game;

InterfaceOnBottom::InterfaceOnBottom()
{
    gridLayout->setMargin(0);
    gridLayout->setSpacing(0);
    gridLayout->setRowMinimumHeight(1, this->height()/8);
    gridLayout->setColumnMinimumWidth(4, 200);

    setLayout(gridLayout);

    gridLayout->addWidget(textMoney, 0, 0, Qt::AlignHCenter);
    gridLayout->addWidget(qlcdMoney, 0, 1);

    gridLayout->addWidget(textHP, 0, 2, Qt::AlignHCenter);
    gridLayout->addWidget(qlcdHP, 0, 3);

    gridLayout->addWidget(textEnemiesLeft, 1, 0, Qt::AlignHCenter);
    gridLayout->addWidget(qlcdEnemiesLeft, 1, 1);

    gridLayout->addWidget(textLevel, 1, 2, Qt::AlignHCenter);
    gridLayout->addWidget(qlcdLevel, 1, 3);

    gridLayout->addWidget(buttonStartGame, 0, 4, 2, 1, Qt::AlignHCenter);
    connect(buttonStartGame, SIGNAL(clicked()), game->map->getNewLevelEnemies(), SLOT(startNewLevel()));

    updateMoney();
    updateHp();
    updateLevel();
}

void InterfaceOnBottom::updateMoney()
{
    qlcdMoney->display(QString::number(game->player->getMoney()));
}

void InterfaceOnBottom::updateHp()
{
    qlcdHP->display(QString::number(game->player->getHp()));
}

void InterfaceOnBottom::updateEnemiesLeft()
{
    qlcdEnemiesLeft->display(QString::number(game->map->getNewLevelEnemies()->getEnemiesLeft()));
}

void InterfaceOnBottom::updateLevel()
{
    qlcdLevel->display(QString::number(game->getLevel()));
}
