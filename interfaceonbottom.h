#ifndef INTERFACEONBOTTOM_H
#define INTERFACEONBOTTOM_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>

class InterfaceOnBottom : public QWidget
{
    Q_OBJECT
private:
    QGridLayout * gridLayout = new QGridLayout(this);

    QLabel * textMoney = new QLabel("Money:");
    QLCDNumber * qlcdMoney = new QLCDNumber(5);
    QLabel * textHP = new QLabel("HP:");
    QLCDNumber * qlcdHP = new QLCDNumber(5);

    QLabel * textEnemiesLeft = new QLabel("Enemies left");
    QLCDNumber * qlcdEnemiesLeft = new QLCDNumber(5);

    QLabel * textLevel = new QLabel("Level:");
    QLCDNumber * qlcdLevel = new QLCDNumber(5);

    QPushButton * buttonStartGame = new QPushButton("Start game");

public:
    InterfaceOnBottom();

    void setButtonStartGameCheckable(bool checkable) { buttonStartGame->setCheckable(checkable); }

public slots:
    void updateMoney();
    void updateHp();
    void updateEnemiesLeft();
    void updateLevel();
};

#endif // INTERFACEONBOTTOM_H
