#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    QTimer * timer = new QTimer();

    connect(timer, &QTimer::timeout, this, &Bullet::fireBullet);

    timer->start(50);
}

void Bullet::fireBullet()
{
    setPos(x(), y() - 10);
    if (y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
