#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent= nullptr);
public slots:
    void moveDown();
};

#endif // ENEMY_H
