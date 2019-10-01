#include "interfaceonbottom.h"

#include "game.h"
extern Game * game;

InterfaceOnBottom::InterfaceOnBottom()
{
    vLayout = new QVBoxLayout(this);
    vLayout->setMargin(0);
    vLayout->setSpacing(0);

    vLayout->addWidget(textMoney);

    updateMoney();
    vLayout->addWidget(qlcdMoney);

    setLayout(vLayout);
}

void InterfaceOnBottom::updateMoney()
{
    qlcdMoney->display(QString::number(game->player->getMoney()));
}
