#ifndef INTERFACEONRIGHTSIDE_H
#define INTERFACEONRIGHTSIDE_H

#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "hex.h"
#include "interfacewaitforclickhex.h"
#include "interfacewithtoweroptions.h"
#include "interfacetowerdetails.h"

class InterfaceOnRightSide : public QStackedWidget
{
private:
    InterfaceWaitForClickHex * interfaceWaitForClickHex = new InterfaceWaitForClickHex();
    InterfaceWithTowerOptions * interfaceWithTowerOptions = new InterfaceWithTowerOptions();
    InterfaceTowerDetails * interfaceTowerDetails = new InterfaceTowerDetails();

public:
    InterfaceOnRightSide();

    void setInterface(unsigned short interface) { setCurrentIndex(interface); }
    void setAllConnects();

    InterfaceTowerDetails * getInterfaceTowerDetails() { return interfaceTowerDetails; }
    InterfaceWithTowerOptions * getInterfaceWithTowerOptions() { return interfaceWithTowerOptions; }
};

#endif // INTERFACEONRIGHTSIDE_H
