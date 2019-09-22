#include "interfaceonbottom.h"
#include "game.h"

extern Game * game;

InterfaceOnBottom::InterfaceOnBottom()
{
    vLayout = new QVBoxLayout(this);
    vLayout->setMargin(0);
    vLayout->setSpacing(0);

    button = new QPushButton("sadasdasdasd");
    vLayout->addWidget(button);

    setLayout(vLayout);
}
