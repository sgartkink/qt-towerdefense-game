#include "widgetwaitforclickhex.h"

WidgetWaitForClickHex::WidgetWaitForClickHex(QWidget *parent) : QWidget(parent)
{
    setLayout(vLayout);

    vLayout->addWidget(textClick, 0, Qt::AlignHCenter);
}
