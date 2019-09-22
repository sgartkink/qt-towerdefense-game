#ifndef GLOBAL_CONSTS_H
#define GLOBAL_CONSTS_H

#include <QColor>

const int MAP_SIZE = 8;

const int HEX_SIZE = 40;
const int BULLET_SIZE = 10;
const int ENEMY_SIZE = 20;

const int HEX_EFFECT_STARTING_POSITION = 15;
const int HEX_EFFECT_STARTING_SIZE = 10;

const int BLUE_TOWER_NR = 0;
const int GREEN_TOWER_NR = 1;
const int DARKCYAN_TOWER_NR = 2;
const int WHITE_TOWER_NR = 3;
const int YELLOW_TOWER_NR = 4;

const Qt::GlobalColor HEX_UNDER_MOUSE_COLOR = Qt::red;
const Qt::GlobalColor HEX_IN_TOWER_RANGE_COLOR = Qt::gray;
const Qt::GlobalColor HEX_NORMAL_COLOR = Qt::black;
const Qt::GlobalColor HEX_PEN_COLOR = Qt::cyan;
const Qt::GlobalColor EFFECT_PEN_COLOR = Qt::darkMagenta;
const Qt::GlobalColor ENEMY_COLOR = Qt::white;

#endif // GLOBAL_CONSTS_H
