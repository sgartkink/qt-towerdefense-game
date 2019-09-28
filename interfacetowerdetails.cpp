#include "interfacetowerdetails.h"

#include "game.h"
extern Game * game;

InterfaceTowerDetails::InterfaceTowerDetails(QWidget *parent) : QWidget(parent)
{
    setLayout(gridLayout);

    gridLayout->addWidget(textTowerName, 0, 0, Qt::AlignHCenter);
    gridLayout->addWidget(textLevel);
    gridLayout->addWidget(qlcdLevel);
    gridLayout->addWidget(textDamage);
    gridLayout->addWidget(qlcdDamage);
    gridLayout->addWidget(textUpgradeCost);
    gridLayout->addWidget(qlcdUpgradeCost);
    gridLayout->addWidget(buttonUpgrade);
}

void InterfaceTowerDetails::setActiveTower(Tower *tower)
{
    if (activeTower)
        disconnect(activeTower);

    activeTower = tower;
    setTowerNameAndVectorPrices();
//    connect(buttonUpgrade, SIGNAL(clicked()), activeTower, SLOT(increaseLevel()));
    connect(buttonUpgrade, &QPushButton::clicked, [this](){ activeTower->increaseLevelAndReducePlayerMoney(vectorTowerPrices_NR); });
    disconnect(this);
    connect(buttonUpgrade, SIGNAL(clicked()), this, SLOT(updateInterface()));
    updateInterface();
}

void InterfaceTowerDetails::updateInterface()
{
    qlcdLevel->display(activeTower->getCurrentLevel());
    qlcdDamage->display(QString::number(activeTower->getDamage()));

    checkTowerPriceDependsOnLevel();

    buttonUpgrade->setEnabled(true);

    if (activeTower->getCurrentLevel() == MAX_TOWER_LEVEL)
        buttonUpgrade->setEnabled(false);

    if (game->player->getMoney() < qlcdUpgradeCost->intValue())
        buttonUpgrade->setEnabled(false);
}

void InterfaceTowerDetails::setTowerNameAndVectorPrices()
{
    QString name = activeTower->pen().color().name();
    if (name == "#0000ff")
    {
        textTowerName->setText("Blue Tower");
        vectorTowerPrices_NR = BLUE_TOWER_PRICES_NR;
    }
    else if (name == "#00ff00")
    {
        textTowerName->setText("Green Tower");
        vectorTowerPrices_NR = GREEN_TOWER_PRICES_NR;
    }
    else if (name == "#ffffff")
    {
        textTowerName->setText("White tower");
        vectorTowerPrices_NR = WHITE_TOWER_PRICES_NR;
    }
    else if (name == "#ffff00")
    {
        textTowerName->setText("Yellow Tower");
        vectorTowerPrices_NR = YELLOW_TOWER_PRICES_NR;
    }
    else
    {
        textTowerName->setText("Dark Cyan Tower");
        vectorTowerPrices_NR = DARK_CYAN_TOWER_PRICES_NR;
    }
}

void InterfaceTowerDetails::checkTowerPriceDependsOnLevel()
{
    if (activeTower->getCurrentLevel() != MAX_TOWER_LEVEL)
        qlcdUpgradeCost->display(QString::number(activeTower->getPrice(vectorTowerPrices_NR)));
    else
        qlcdUpgradeCost->display(0);
}
