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