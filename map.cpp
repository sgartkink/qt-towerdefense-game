#include "map.h"
#include "enemy.h"

#include "game.h"
extern Game * game;

Map::Map()
{
    setStyleSheet("border: 0px");

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();

    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(view);
    setLayout(layout);
}

void Map::createAllHexesAndAddToScene()
{
    vectorAllHexes.resize(MAP_SIZE);

    //offset coordinate system
    for (int y = 0; y < MAP_SIZE; y++)
        for (int x = 0; x < MAP_SIZE; x++)
        {
            Hex * hex = new Hex(x, y);
            hex->setFlag(QGraphicsItem::ItemIsFocusable);
            hex->setPos(
                        HEX_SIZE*sqrt(3)*x + HEX_SIZE/2*sqrt(3)*(y%2),
                        HEX_SIZE*1.5*y
                        );

            vectorAllHexes[y].append(hex);
            scene->addItem(hex);
        }
}

void Map::hexWasClicked(Hex *h)
{
    if (activeHex)
        if (activeHex->hasTower())
            paintHexesInTowerRange(HEX_NORMAL_COLOR, false);

    if (activeHex != h)
    {
        deleteAndRemoveEffectFromScene();
        activeHex = h;
        createAndAddEffectToScene();
    }

    if (activeHex->hasTower())
    {
        paintHexesInTowerRange(HEX_IN_TOWER_RANGE_COLOR, true);
        game->interfaceOnTheRightSide->getInterfaceTowerDetails()->setActiveTower(activeHex->getTower());
        game->interfaceOnTheRightSide->setInterface(INTERFACE_TOWER_DETAILS);
    }
    else
        game->interfaceOnTheRightSide->setInterface(INTERFACE_WITH_TOWER_OPTIONS_NR);

    if (!isPathCreated)
    {
        setPathForEnemy();
        isPathCreated = true;
    }

    Enemy * enemy = new Enemy(pathForEnemy->getPoints());
    scene->addItem(enemy);
    vectorAllEnemies.append(enemy);
}

void Map::createAndAddEffectToScene()
{
    effect = new ChosenHexEffect();
    effect->setPos(activeHex->x(), activeHex->y());
    scene->addItem(effect);
}

void Map::deleteAndRemoveEffectFromScene()
{
    if (effect)
    {
        scene->removeItem(effect);
        delete effect;
        effect = nullptr;
    }
}

void Map::paintHexesInTowerRange(Qt::GlobalColor color, bool inRange)
{
    for (int i = 0; i < MAP_SIZE; i++)
        for (int j = 0; j < MAP_SIZE; j++)
            if (distaneBetweenTwoHexes(vectorAllHexes[i][j], activeHex) <= activeHex->getTowerAttackRange() &&
                distaneBetweenTwoHexes(vectorAllHexes[i][j], activeHex) != 0)
            {
                vectorAllHexes[i][j]->changeHexBrushAndUpdate(color);
                vectorAllHexes[i][j]->setInRangeChosenHexWithTower(inRange);
            }
}

void Map::mousePressEvent(QMouseEvent *event)
{
    game->interfaceOnTheRightSide->setInterface(INTERFACE_WAIT_FOR_CLICK_HEX_NR);
    if (activeHex)
    {
        if (activeHex->hasTower())
            paintHexesInTowerRange(HEX_NORMAL_COLOR, false);
        deleteAndRemoveEffectFromScene();
    }
    activeHex = nullptr;
}

unsigned int Map::distaneBetweenTwoHexes(Hex *a, Hex *b)
{
    return (abs(a->getXAxial() - b->getXAxial()) + abs(a->getY() - b->getY()) + abs(a->getZ() - b->getZ())) / 2;
}

void Map::setPathForEnemy()
{
    pathForEnemy = new PathForEnemy();
}

void Map::createTower(int nr)
{
    if (!activeHex->hasTower())
    {
        Tower * tower = nullptr;
        switch(nr)
        {
        case BLUE_TOWER_NR: tower = new BlueTower();
            break;
        case GREEN_TOWER_NR: tower = new GreenTower();
            break;
        case DARKCYAN_TOWER_NR: tower = new DarkCyanTower();
            break;
        case WHITE_TOWER_NR: tower = new WhiteTower();
            break;
        case YELLOW_TOWER_NR: tower = new YellowTower();
            break;
        default: tower = new GreenTower();
        }
        tower->setPos(activeHex->x(), activeHex->y());
        tower->setParentHex(activeHex);
        vectorAllTowers.append(tower);
        scene->addItem(tower);

        activeHex->setHasTower(true);
        activeHex->setTower(tower);

        paintHexesInTowerRange(HEX_IN_TOWER_RANGE_COLOR, true);

        QTimer * collisionTimer = new QTimer;
        connect(collisionTimer, SIGNAL(timeout()), this, SLOT(checkCollidings()));
        collisionTimer->start(150);

        game->interfaceOnTheRightSide->getInterfaceTowerDetails()->setActiveTower(activeHex->getTower());
        game->interfaceOnTheRightSide->setInterface(INTERFACE_TOWER_DETAILS);
    }
}

void Map::checkCollidings()
{
    for (auto itTower = vectorAllTowers.begin(); itTower != vectorAllTowers.end(); ++itTower)
    {
        Enemy * enemyDestination = nullptr;

        QVector<Hex*> vectorHexesInRange;
        for (int i = 0; i < MAP_SIZE; i++)
            for (int j = 0; j < MAP_SIZE; j++)
                if (distaneBetweenTwoHexes(vectorAllHexes[i][j], (*itTower)->getParentHex()) <= (*itTower)->getAttackRange() &&
                    distaneBetweenTwoHexes(vectorAllHexes[i][j], (*itTower)->getParentHex()) != 0)
                    vectorHexesInRange.append(vectorAllHexes[i][j]);

        for (auto itHex = vectorHexesInRange.begin(); itHex != vectorHexesInRange.end(); ++itHex)
        {
            QList<QGraphicsItem *> colliding_items = (*itHex)->collidingItems();
            for (int i = 0; i < colliding_items.size(); i++)
            {
                Enemy * currentlyCheckedEnemy = dynamic_cast<Enemy *>(colliding_items[i]);

                if (currentlyCheckedEnemy)
                {
                    if (!enemyDestination)
                        enemyDestination = currentlyCheckedEnemy;

                    if (currentlyCheckedEnemy->getNr() < enemyDestination->getNr())
                        enemyDestination = currentlyCheckedEnemy;
                }
            }
        }

        if (enemyDestination)
            (*itTower)->enemyTargeted(enemyDestination);
    }
}
