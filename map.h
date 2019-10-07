#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QObject>
#include <QVector>
#include <QBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtMath>

#include "hex.h"
#include "chosenhexeffect.h"
#include "towers/bluetower.h"
#include "towers/greentower.h"
#include "towers/darkcyantower.h"
#include "towers/whitetower.h"
#include "towers/yellowtower.h"
#include "enemy.h"
#include "towerrangeattack.h"
#include "pathforenemy.h"
#include "newlevelenemies.h"

/**
 * TODO:
 * 1. check collidings works but it needs a lot of optimalization
 * range for each tower should be calculated once
 * it should be done in class TowerRangeAttack
 */

class Map : public QWidget
{
    Q_OBJECT
private:
    QBoxLayout * layout = new QBoxLayout(QBoxLayout::LeftToRight);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);
    PathForEnemy * pathForEnemy = nullptr;
    Hex * activeHex = nullptr;
    ChosenHexEffect * effect = nullptr;
    QVector<QVector <Hex*>> vectorAllHexes;
    QVector<Tower*> vectorAllTowers;
    QVector<Enemy*> vectorAllEnemies;
    NewLevelEnemies * newLevelEnemies = new NewLevelEnemies;

    void createAndAddEffectToScene();
    void deleteAndRemoveEffectFromScene();

    void mousePressEvent(QMouseEvent *event);

    unsigned int distaneBetweenTwoHexes(Hex * a, Hex * b);

public:
    Map();

    QGraphicsScene * getScene() { return scene; }
    Hex * getHex(int x, int y) { return vectorAllHexes[y][x]; }
    Hex * getActiveHex() { return activeHex; }
    NewLevelEnemies * getNewLevelEnemies() { return newLevelEnemies; }
    QList<QPointF> getPathForEnemy() { return pathForEnemy->getPoints(); }

    void createAllHexesAndAddToScene();
    void setPathForEnemy();
    void hexWasClicked(Hex * h);
    void changeOpacityHexesOutOfReach(qreal opacity, Hex * hex);

public slots:
    void createTower(int nr);
    void checkCollidings();
};

#endif // MAP_H
