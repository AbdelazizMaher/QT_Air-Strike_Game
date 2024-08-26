#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <QGraphicsScene>
#include <QKeyEvent>

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (x() > 0)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 800)
            setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Space) {
        Bullet * bullet = new Bullet();

        bullet->setPos(x() + 45, y());
        //TODO --->> CHECK NULLPTR
        scene()->addItem(bullet);
    }
}

void Player::spawnEnemy()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
