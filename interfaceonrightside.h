#ifndef INTERFACEONRIGHTSIDE_H
#define INTERFACEONRIGHTSIDE_H

#include <QStackedWidget>

#include "hex.h"
#include "widgetwaitforclickhex.h"
#include "widgetwithtoweroptions.h"
#include "widgettowerdetails.h"
#include "widgetendgame.h"

class InterfaceOnRightSide : public QStackedWidget
{
private:
    WidgetWaitForClickHex * widgetWaitForClickHex = new WidgetWaitForClickHex();
    WidgetWithTowerOptions * widgetWithTowerOptions = new WidgetWithTowerOptions();
    WidgetTowerDetails * widgetTowerDetails = new WidgetTowerDetails();
    WidgetEndGame * widgetEndGame = new WidgetEndGame();

public:
    InterfaceOnRightSide();

    void setWidget(unsigned short widget) { setCurrentIndex(widget); }
    void setAllConnects();

    WidgetWithTowerOptions * getInterfaceWithTowerOptions() { return widgetWithTowerOptions; }
    WidgetTowerDetails * getWidgetTowerDetails() { return widgetTowerDetails; }
    WidgetEndGame * getWidgetEndGame() { return widgetEndGame; }
};

#endif // INTERFACEONRIGHTSIDE_H
