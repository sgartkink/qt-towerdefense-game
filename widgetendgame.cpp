#include "widgetendgame.h"
#include <QtDebug>

#include "game.h"
extern Game * game;

WidgetEndGame::WidgetEndGame()
{
    setLayout(vLayout);

    vLayout->addWidget(textGameHasEnded);
    vLayout->addWidget(textWhoHasWon);
    vLayout->addWidget(buttonRestartGame);

    connect(buttonRestartGame, SIGNAL(clicked()), this, SLOT(restartGame()));
}

void WidgetEndGame::setIfPlayerWon(bool playerWon)
{
    if (playerWon)
        textWhoHasWon->setText("Player has won!");
    else
        textWhoHasWon->setText("Player has lost!");
}

void WidgetEndGame::restartGame()
{
    game->player->resetPlayer();
    game->resetLevel();
    game->map->resetMap();
    game->interfaceOnTheRightSide->setWidget(WIDGET_WAIT_FOR_CLICK_HEX_NR);
    game->interfaceOnBottom->setButtonStartGameEnabled(true);
}
