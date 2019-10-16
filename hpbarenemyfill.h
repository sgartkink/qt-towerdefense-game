#ifndef HPBARENEMYFILL_H
#define HPBARENEMYFILL_H

#include <QGraphicsRectItem>
#include <QBrush>

class HPBarEnemyFill : public QGraphicsRectItem
{
    const int MAX_HP;
    QBrush brush = QBrush(Qt::green);

public:
    HPBarEnemyFill(int MAX_HP_);

    void changeRect(int currentHP);
};

#endif // HPBARENEMYFILL_H
