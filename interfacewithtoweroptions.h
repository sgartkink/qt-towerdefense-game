#ifndef INTERFACEWITHTOWEROPTIONS_H
#define INTERFACEWITHTOWEROPTIONS_H

#include <QWidget>
#include <QVBoxLayout>

#include "widgettoweroptions.h"
#include "towers_prices.h"

class InterfaceWithTowerOptions : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout * vLayout = new QVBoxLayout();

    WidgetTowerOptions * widgetBlueTowerOptions = new WidgetTowerOptions("Blue tower", BLUE_TOWER_PRICES[0]);
    WidgetTowerOptions * widgetGreenTowerOptions = new WidgetTowerOptions("Green tower", GREEN_TOWER_PRICES[0]);
    WidgetTowerOptions * widgetDarkCyanTowerOptions = new WidgetTowerOptions("Dark Cyan tower", DARK_CYAN_TOWER_PRICES[0]);
    WidgetTowerOptions * widgetWhiteTowerOptions = new WidgetTowerOptions("White tower", WHITE_TOWER_PRICES[0]);
    WidgetTowerOptions * widgetYellowTowerOptions = new WidgetTowerOptions("Yellow tower", YELLOW_TOWER_RRICES[0]);

public:
    explicit InterfaceWithTowerOptions(QWidget *parent = nullptr);

    void setAllButtonConnects();
};

#endif // INTERFACEWITHTOWEROPTIONS_H
