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

void Player::increaseHp(int increased)
{
    hp += increased;

    game->interfaceOnBottom->updateHp();
}

void Player::decreaseHp(int decreased)
{
    hp -= decreased;

    game->interfaceOnBottom->updateHp();

//    if (hp <= 0)
        //end game
}

void Player::updateUpgradeAndBuyButtons()
{
    game->interfaceOnBottom->updateMoney();
    game->interfaceOnTheRightSide->getInterfaceWithTowerOptions()->updateButtons();
}
