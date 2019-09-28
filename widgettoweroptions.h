#ifndef WIDGETTOWEROPTIONS_H
#define WIDGETTOWEROPTIONS_H

#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>

class WidgetTowerOptions : public QFrame
{
private:
    QGridLayout * gridLayout = new QGridLayout();
    QLabel * towerName = new QLabel();
    QLabel * textPRICE = new QLabel("Price:");
    QLCDNumber * qlcdPrice = new QLCDNumber(5);
    QPushButton * buyTowerButton = new QPushButton();

    const unsigned int towerPrice;

public:
    WidgetTowerOptions(QString towerName_, unsigned int towerPrice_);

    QPushButton * getButton() { return buyTowerButton; }

    void updateButton();
};

#endif // WIDGETTOWEROPTIONS_H
