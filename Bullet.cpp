#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>


Bullet::Bullet(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/assets/images/bullet.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::onFireTimeout);
    timer->start(50);
}

void Bullet::onFireTimeout()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (auto item : colliding_items)
    {
        if (dynamic_cast<Enemy *>(item))
        {
            emit bulletCollided(item, this);
            return;
        }
    }

    setPos(x(), y() - 10);
    if (y() < 0)
        emit bulletDestroyed(this);
}
