#ifndef INTERFACEONRIGHTSIDE_H
#define INTERFACEONRIGHTSIDE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "hex.h"

class InterfaceOnRightSide : public QWidget
{
private:
    QVBoxLayout * vLayout;
    QPushButton * buttonBlueTower = new QPushButton("Add blue tower");
    QPushButton * buttonGreenTower = new QPushButton("Add green tower");
    QPushButton * buttonDarkCyanTower = new QPushButton("Add dark cyan tower");
    QPushButton * buttonWhiteTower = new QPushButton("Add white tower");
    QPushButton * buttonYellowTower = new QPushButton("Add yellow tower");
    QLabel * text;

    void createButton(QPushButton * button);
    void changeButtonsVisible(bool v);

public:
    InterfaceOnRightSide();

    void showTowerButtons();
    void hideTowerButtons();
    void setAllConnects();
};

#endif // INTERFACEONRIGHTSIDE_H
