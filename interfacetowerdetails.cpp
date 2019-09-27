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
        disconnect(buttonUpgrade, SIGNAL(clicked()), activeTower, SLOT(increaseLevel()));

    activeTower = tower;
    connect(buttonUpgrade, SIGNAL(clicked()), activeTower, SLOT(increaseLevel()));
    disconnect(this);
    connect(buttonUpgrade, SIGNAL(clicked()), this, SLOT(updateInterface()));
    updateInterface();
}

void InterfaceTowerDetails::updateInterface()
{
    qlcdLevel->display(activeTower->getCurrentLevel());
    qlcdDamage->display(QString::number(activeTower->getDamage()));

    if (activeTower->getCurrentLevel() == MAX_TOWER_LEVEL)
        buttonUpgrade->setEnabled(false);
    else
        buttonUpgrade->setEnabled(true);

    checkTowerColor();
}

void InterfaceTowerDetails::checkTowerColor()
{
    QString name = activeTower->pen().color().name();
    if (name == "#0000ff")
        textTowerName->setText("Blue Tower");
    else if (name == "#00ff00")
        textTowerName->setText("Green Tower");
    else if (name == "#ffffff")
        textTowerName->setText("White tower");
    else if (name == "#ffff00")
        textTowerName->setText("Yellow Tower");
    else
        textTowerName->setText("Dark Cyan Tower");
}
