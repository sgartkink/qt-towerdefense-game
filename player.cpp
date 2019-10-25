#include "player.h"

#include "game.h"
extern Game * game;

Player::Player()
{

}

void Player::increaseMoney(unsigned int increased)
{
    money += increased;
    updateUpgradeAndBuyButtons();
}

void Player::decreaseMoney(unsigned int decreased)
{
    money -= decreased;
    updateUpgradeAndBuyButtons();
}

void Player::updateUpgradeAndBuyButtons()
{
    game->interfaceOnBottom->updateMoney();
    game->interfaceOnTheRightSide->getInterfaceWithTowerOptions()->updateButtons();
}

void Player::increaseHp(int increased)
{
    hp += increased;
    game->interfaceOnBottom->updateHp();
}

void Player::decreaseHp(int decreased)
{
    hp -= decreased;
    game->interfaceOnBottom->updateHp();

    checkIfPlayerIsDead();
}

void Player::checkIfPlayerIsDead()
{
    if (hp < 0)
        endGame();
}

void Player::endGame()
{
    game->interfaceOnTheRightSide->getWidgetEndGame()->setIfPlayerWon(false);
    game->interfaceOnBottom->setButtonStartGameEnabled(false);
    game->interfaceOnTheRightSide->setWidget(WIDGET_END_GAME_NR);
}

void Player::resetPlayer()
{
    money = 2000;
    hp = 10;
    updateUpgradeAndBuyButtons();
}
