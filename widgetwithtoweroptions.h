#ifndef INTERFACEWITHTOWEROPTIONS_H
#define INTERFACEWITHTOWEROPTIONS_H

#include <QWidget>
#include <QVBoxLayout>

#include "widgettoweroptions.h"
#include "towers_prices.h"

class WidgetWithTowerOptions : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout * vLayout = new QVBoxLayout();

    WidgetTowerOptions * widgetBlueTowerOptions = new WidgetTowerOptions("Blue tower", VECTOR_TOWER_PRICES[BLUE_TOWER_PRICES_NR][0]);
    WidgetTowerOptions * widgetGreenTowerOptions = new WidgetTowerOptions("Green tower", VECTOR_TOWER_PRICES[GREEN_TOWER_PRICES_NR][0]);
    WidgetTowerOptions * widgetDarkCyanTowerOptions = new WidgetTowerOptions("Dark Cyan tower", VECTOR_TOWER_PRICES[DARK_CYAN_TOWER_PRICES_NR][0]);
    WidgetTowerOptions * widgetWhiteTowerOptions = new WidgetTowerOptions("White tower", VECTOR_TOWER_PRICES[WHITE_TOWER_PRICES_NR][0]);
    WidgetTowerOptions * widgetYellowTowerOptions = new WidgetTowerOptions("Yellow tower", VECTOR_TOWER_PRICES[YELLOW_TOWER_PRICES_NR][0]);

public:
    explicit WidgetWithTowerOptions(QWidget *parent = nullptr);

    void setAllButtonConnects();

public slots:
    void updateButtons();
};

#endif // INTERFACEWITHTOWEROPTIONS_H
