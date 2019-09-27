#include "interfacewaitforclickhex.h"

InterfaceWaitForClickHex::InterfaceWaitForClickHex(QWidget *parent) : QWidget(parent)
{
    setLayout(vLayout);

    vLayout->addWidget(textClick, 0, Qt::AlignHCenter);
}
