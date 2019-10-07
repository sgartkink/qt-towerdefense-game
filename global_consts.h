#ifndef GLOBAL_CONSTS_H
#define GLOBAL_CONSTS_H

#include <QColor>

const int MAP_SIZE = 8;

const int HEX_SIZE = 40;
const int TOWER_SIZE = HEX_SIZE/4;
const int BULLET_SIZE = HEX_SIZE/4;
const int ENEMY_SIZE = HEX_SIZE/2;

const short MAX_TOWER_LEVEL = 5;

const qreal OPACITY_NORMAL = 1;
const qreal OPACITY_HOVER = 0.6;
const qreal OPACITY_OUT_OF_REACH = 0.2;

const short BLUE_TOWER_NR = 0;
const short GREEN_TOWER_NR = 1;
const short DARKCYAN_TOWER_NR = 2;
const short WHITE_TOWER_NR = 3;
const short YELLOW_TOWER_NR = 4;

const short INTERFACE_WAIT_FOR_CLICK_HEX_NR = 0;
const short INTERFACE_WITH_TOWER_OPTIONS_NR = 1;
const short INTERFACE_TOWER_DETAILS = 2;

const Qt::GlobalColor HEX_UNDER_MOUSE_COLOR = Qt::red;
const Qt::GlobalColor HEX_IN_TOWER_RANGE_COLOR = Qt::gray;
const Qt::GlobalColor HEX_NORMAL_COLOR = Qt::black;
const Qt::GlobalColor HEX_PEN_COLOR = Qt::cyan;
const Qt::GlobalColor EFFECT_PEN_COLOR = Qt::darkMagenta;
const Qt::GlobalColor ENEMY_COLOR = Qt::white;
const Qt::GlobalColor PATH_COLOR = Qt::yellow;

#endif // GLOBAL_CONSTS_H
