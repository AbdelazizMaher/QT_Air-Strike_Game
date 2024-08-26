#include "Bullet.h"
#include "Enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    QTimer * timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Bullet::fireBullet);

    timer->start(50);
}

void Bullet::fireBullet()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    setPos(x(), y() - 10);
    if (y() + rect().height() < 0)
    {
        //TODO --->> CHECK NULLPTR
        scene()->removeItem(this);
        // TODO not best practice
        delete this;
    }
}
