#include "map.h"

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

    connect(collisionTimer, SIGNAL(timeout()), this, SLOT(checkCollidings()));
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

void Map::setPathForEnemy()
{
    pathForEnemy = new PathForEnemy();
}

void Map::hexWasClicked(Hex *h)
{
    checkIfActiveHexHasTower();
    checkIfActiveHexIsDifferentThanClickedHex(h);
    checkIfActiveHexHasTowerOrPath();
}

void Map::checkIfActiveHexHasTower()
{
    if (activeHex)
        if (activeHex->getTower())
        {
            changeOpacityHexesOutOfReach(OPACITY_NORMAL, activeHex);
            activeHex->getTower()->setTowerRangeAttackVisibility(false);
        }
}

void Map::checkIfActiveHexIsDifferentThanClickedHex(Hex *hex)
{
    if (activeHex != hex)
        changeActiveHexAndSetEffectAgain(hex);
}

void Map::changeActiveHexAndSetEffectAgain(Hex *hex)
{
    deleteAndRemoveEffectFromScene();
    activeHex = hex;
    createAndAddEffectToScene();
}

void Map::checkIfActiveHexHasTowerOrPath()
{
    if (activeHex->getTower())
        changeOpacityAndRightInterface();
    else if (!activeHex->hasPath())
        game->interfaceOnTheRightSide->setInterface(INTERFACE_WITH_TOWER_OPTIONS_NR);
    else
        game->interfaceOnTheRightSide->setInterface(INTERFACE_WAIT_FOR_CLICK_HEX_NR);
}

void Map::changeOpacityAndRightInterface()
{
    changeOpacityHexesOutOfReach(OPACITY_OUT_OF_REACH, activeHex);
    game->interfaceOnTheRightSide->getWidgetTowerDetails()->setActiveTower(activeHex->getTower());
    game->interfaceOnTheRightSide->setInterface(INTERFACE_TOWER_DETAILS);
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

void Map::changeOpacityHexesOutOfReach(qreal opacity, Hex *hex)
{
    for (int i = 0; i < MAP_SIZE; i++)
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (hex->getTower())
            if (!(distaneBetweenTwoHexes(vectorAllHexes[i][j], hex) <= hex->getTowerAttackRange() &&
                distaneBetweenTwoHexes(vectorAllHexes[i][j], hex) != 0))
                vectorAllHexes[i][j]->changeOpacity(opacity);
        }
}

void Map::mousePressEvent(QMouseEvent *event)
{
    game->interfaceOnTheRightSide->setInterface(INTERFACE_WAIT_FOR_CLICK_HEX_NR);
    if (activeHex)
    {
        if (activeHex->getTower())
        {
            changeOpacityHexesOutOfReach(OPACITY_NORMAL, activeHex);
            activeHex->getTower()->setTowerRangeAttackVisibility(false);
        }
        deleteAndRemoveEffectFromScene();
    }
    activeHex = nullptr;
}

unsigned int Map::distaneBetweenTwoHexes(Hex *a, Hex *b)
{
    return (abs(a->getXAxial() - b->getXAxial()) + abs(a->getY() - b->getY()) + abs(a->getZ() - b->getZ())) / 2;
}

void Map::createTower(int nr)
{
    if (!activeHex->getTower())
    {
        Tower * tower = nullptr;
        switch(nr)
        {
        case BLUE_TOWER_NR:
            tower = new BlueTower(activeHex->pos());
            break;
        case GREEN_TOWER_NR:
            tower = new GreenTower(activeHex->pos());
            break;
        case DARKCYAN_TOWER_NR:
            tower = new DarkCyanTower(activeHex->pos());
            break;
        case WHITE_TOWER_NR:
            tower = new WhiteTower(activeHex->pos());
            break;
        case YELLOW_TOWER_NR:
            tower = new YellowTower(activeHex->pos());
            break;
        default:
            tower = new GreenTower(activeHex->pos());
        }
        tower->setParentHex(activeHex);
        vectorAllTowers.append(tower);

        activeHex->setTower(tower);

        changeOpacityHexesOutOfReach(OPACITY_OUT_OF_REACH, activeHex);

        game->interfaceOnTheRightSide->getWidgetTowerDetails()->setActiveTower(activeHex->getTower());
        game->interfaceOnTheRightSide->setInterface(INTERFACE_TOWER_DETAILS);
    }
}

void Map::checkCollidings()
{
    for (auto itTower = vectorAllTowers.begin(); itTower != vectorAllTowers.end(); ++itTower)
    {
        Enemy * enemyDestination = nullptr;

        QList<QGraphicsItem *> colliding_items = (*itTower)->getTowerRangeAttack()->collidingItems();
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

        if (enemyDestination)
            (*itTower)->enemyTargeted(enemyDestination);
    }
}

void Map::startCollisionTimer()
{
    collisionTimer->start(150);
}

void Map::stopCollistionTimer()
{
    collisionTimer->stop();
}

Map::~Map()
{
    collisionTimer->stop();
}
