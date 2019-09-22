#ifndef INTERFACEONBOTTOM_H
#define INTERFACEONBOTTOM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class InterfaceOnBottom : public QWidget
{
private:
    QVBoxLayout * vLayout;
    QPushButton * button = new QPushButton();
public:
    InterfaceOnBottom();
};

#endif // INTERFACEONBOTTOM_H
