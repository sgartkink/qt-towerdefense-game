#ifndef TOWERS_PRICES_H
#define TOWERS_PRICES_H

#include <QVector>

const unsigned short BLUE_TOWER_PRICES_NR = 0;
const unsigned short DARK_CYAN_TOWER_PRICES_NR = 1;
const unsigned short GREEN_TOWER_PRICES_NR = 2;
const unsigned short WHITE_TOWER_PRICES_NR = 3;
const unsigned short YELLOW_TOWER_PRICES_NR = 4;

const QVector<QVector<unsigned int>> VECTOR_TOWER_PRICES = {
    { 100, 200, 300, 400, 500 },
    { 50, 100, 150, 200, 250 },
    { 70, 120, 170, 220, 270 },
    { 200, 400, 600, 800, 1000 },
    { 150, 250, 350, 450, 550 }
};
#endif // TOWERS_PRICES_H
