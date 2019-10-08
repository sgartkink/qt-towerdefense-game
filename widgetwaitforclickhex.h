#ifndef INTERFACEWAITFORCLICKHEX_H
#define INTERFACEWAITFORCLICKHEX_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class WidgetWaitForClickHex : public QWidget
{
private:
    QVBoxLayout * vLayout = new QVBoxLayout();
    QLabel * textClick = new QLabel("Click any hex");

public:
    explicit WidgetWaitForClickHex(QWidget *parent = nullptr);
};

#endif // INTERFACEWAITFORCLICKHEX_H
