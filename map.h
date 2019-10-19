#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QBoxLayout>
#include <QGraphicsView>
#include <QVector>
#include <QtMath>

#include "newlevelenemies.h"
#include "pathforenemy.h"
#include "hex.h"
#include "chosenhexeffect.h"
#include "enemy.h"
#include "towers/bluetower.h"
#include "towers/greentower.h"
#include "towers/darkcyantower.h"
#include "towers/whitetower.h"
#include "towers/yellowtower.h"

class Map : public QWidget
{
    Q_OBJECT
private:
    QBoxLayout * layout = new QBoxLayout(QBoxLayout::LeftToRight);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);
    NewLevelEnemies * newLevelEnemies = new NewLevelEnemies();
    QTimer * collisionTimer = new QTimer(this);
    PathForEnemy * pathForEnemy = nullptr;
    Hex * activeHex = nullptr;
    ChosenHexEffect * effect = nullptr;
    QVector<QVector <Hex*>> vectorAllHexes;
    QVector<Tower*> vectorAllTowers;

    void createAndAddEffectToScene();
    void deleteAndRemoveEffectFromScene();
    void checkIfActiveHexHasTower();
    void checkIfActiveHexIsDifferentThanClickedHex(Hex * hex);
    void changeActiveHexAndSetEffectAgain(Hex * hex);
    void checkIfActiveHexHasTowerOrPath();
    void changeOpacityAndRightInterface();

    void mousePressEvent(QMouseEvent *event);

    unsigned int distaneBetweenTwoHexes(Hex * a, Hex * b);

public:
    Map();
    ~Map();

    QGraphicsScene * getScene() { return scene; }
    Hex * getHex(int x, int y) { return vectorAllHexes[y][x]; }
    NewLevelEnemies * getNewLevelEnemies() { return newLevelEnemies; }
    QList<QPointF> getPathForEnemy() { return pathForEnemy->getPoints(); }
    Hex * getActiveHex() { return activeHex; }

    void createAllHexesAndAddToScene();
    void setPathForEnemy();
    void hexWasClicked(Hex * h);
    void changeOpacityHexesOutOfReach(qreal opacity, Hex * hex);
    void startCollisionTimer();
    void stopCollistionTimer();

public slots:
    void createTower(int nr);
    void checkCollidings();
};

#endif // MAP_H
