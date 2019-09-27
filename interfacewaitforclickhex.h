#ifndef INTERFACEWAITFORCLICKHEX_H
#define INTERFACEWAITFORCLICKHEX_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class InterfaceWaitForClickHex : public QWidget
{
private:
    QVBoxLayout * vLayout = new QVBoxLayout();
    QLabel * textClick = new QLabel("Click any hex");
public:
    explicit InterfaceWaitForClickHex(QWidget *parent = nullptr);
};

#endif // INTERFACEWAITFORCLICKHEX_H
