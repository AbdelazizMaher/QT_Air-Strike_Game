#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();
public slots:
    void moveDown();
};

#endif // ENEMY_H
