#include "widgettoweroptions.h"
#include <QtDebug>

#include "game.h"
extern Game * game;

WidgetTowerOptions::WidgetTowerOptions(QString towerName_, unsigned int towerPrice_)
    : towerPrice(towerPrice_)
{
    setLineWidth(1);
    setFrameShape(QFrame::Box);
    setLayout(gridLayout);

    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);

    towerName->setText(towerName_);
    qlcdPrice->display(QString::number(towerPrice_));
    buyTowerButton->setText("Buy " + towerName_);
    updateButton();

    connect(buyTowerButton, &QPushButton::clicked, [towerPrice_](){ game->player->decreaseMoney(towerPrice_); });

    gridLayout->addWidget(towerName, 0, 0, 2, 1);
    gridLayout->addWidget(textPRICE, 0, 1);
    gridLayout->addWidget(qlcdPrice, 1, 1);
    gridLayout->addWidget(buyTowerButton, 2, 0, 1, 2);
}

void WidgetTowerOptions::updateButton()
{
    buyTowerButton->setEnabled(true);

    if (game->player->getMoney() < towerPrice)
    {
        buyTowerButton->setEnabled(false);
    }
}
