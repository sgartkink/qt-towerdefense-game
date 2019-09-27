#ifndef INTERFACETOWERDETAILS_H
#define INTERFACETOWERDETAILS_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>

#include "global_consts.h"
#include "tower.h"

class InterfaceTowerDetails : public QWidget
{
    Q_OBJECT
private:
    QGridLayout * gridLayout = new QGridLayout();
    QLabel * textTowerName = new QLabel();
    QPushButton * buttonUpgrade = new QPushButton("Upgrade");
    QLabel * textUpgradeCost = new QLabel("Upgrade cost:");
    QLCDNumber * qlcdUpgradeCost = new QLCDNumber(5);
    QLabel * textDamage = new QLabel("Damage:");
    QLCDNumber * qlcdDamage = new QLCDNumber(5);
    QLabel * textLevel = new QLabel("Level:");
    QLCDNumber * qlcdLevel = new QLCDNumber(5);

    Tower * activeTower = nullptr;

    void checkTowerColor();

public:
    explicit InterfaceTowerDetails(QWidget *parent = nullptr);

public slots:
    void setActiveTower(Tower * tower);
    void updateInterface();
};

#endif // INTERFACETOWERDETAILS_H
