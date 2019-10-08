#include "widgettowerdetails.h"

#include "game.h"
extern Game * game;

WidgetTowerDetails::WidgetTowerDetails(QWidget *parent) : QWidget(parent)
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

void WidgetTowerDetails::setActiveTower(Tower *tower)
{
    activeTower = tower;

    setTowerNameAndVectorPrices();

    QObject::disconnect(conn);
    conn = QObject::connect(buttonUpgrade, &QPushButton::clicked, [this](){
        activeTower->increaseLevelAndReducePlayerMoney(vectorTowerPrices_NR);
    });
    disconnect(this);
    connect(buttonUpgrade, SIGNAL(clicked()), this, SLOT(updateInterface()));

    updateInterface();
}

void WidgetTowerDetails::setTowerNameAndVectorPrices()
{
    Qt::GlobalColor towerColor = activeTower->getTowerColor();

    switch(towerColor)
    {
    case 9:
        textTowerName->setText("Blue Tower");
        vectorTowerPrices_NR = BLUE_TOWER_PRICES_NR;
        break;
    case 16:
        textTowerName->setText("Dark Cyan Tower");
        vectorTowerPrices_NR = DARK_CYAN_TOWER_PRICES_NR;
        break;
    case 8:
        textTowerName->setText("Green Tower");
        vectorTowerPrices_NR = GREEN_TOWER_PRICES_NR;
        break;
    case 3:
        textTowerName->setText("White Tower");
        vectorTowerPrices_NR = WHITE_TOWER_PRICES_NR;
        break;
    case 12:
        textTowerName->setText("Yellow Tower");
        vectorTowerPrices_NR = YELLOW_TOWER_PRICES_NR;
        break;
    default: ;
    }
}

void WidgetTowerDetails::updateInterface()
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

void WidgetTowerDetails::checkTowerPriceDependsOnLevel()
{
    if (activeTower->getCurrentLevel() != MAX_TOWER_LEVEL)
        qlcdUpgradeCost->display(QString::number(activeTower->getPrice(vectorTowerPrices_NR)));
    else
        qlcdUpgradeCost->display(0);
}
