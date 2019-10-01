#ifndef INTERFACEONBOTTOM_H
#define INTERFACEONBOTTOM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>

class InterfaceOnBottom : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout * vLayout;
    QPushButton * button = new QPushButton();

    QLabel * textMoney = new QLabel("Money:");
    QLCDNumber * qlcdMoney = new QLCDNumber(5);

public:
    InterfaceOnBottom();

public slots:
    void updateMoney();
};

#endif // INTERFACEONBOTTOM_H
