#ifndef INTERFACEONRIGHTSIDE_H
#define INTERFACEONRIGHTSIDE_H

#include <QStackedWidget>

#include "hex.h"
#include "widgetwaitforclickhex.h"
#include "widgetwithtoweroptions.h"
#include "widgettowerdetails.h"

class InterfaceOnRightSide : public QStackedWidget
{
private:
    WidgetWaitForClickHex * widgetWaitForClickHex = new WidgetWaitForClickHex();
    WidgetWithTowerOptions * widgetWithTowerOptions = new WidgetWithTowerOptions();
    WidgetTowerDetails * widgetTowerDetails = new WidgetTowerDetails();

public:
    InterfaceOnRightSide();

    void setInterface(unsigned short interface) { setCurrentIndex(interface); }
    void setAllConnects();

    WidgetWithTowerOptions * getInterfaceWithTowerOptions() { return widgetWithTowerOptions; }
    WidgetTowerDetails * getWidgetTowerDetails() { return widgetTowerDetails; }
};

#endif // INTERFACEONRIGHTSIDE_H
