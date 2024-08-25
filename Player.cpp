#include "Player.h"
#include "Bullet.h"

#include <QGraphicsScene>
#include <QKeyEvent>

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Space) {
        Bullet * bullet = new Bullet();

        bullet->setPos(x() + 45, y());
        //TODO --->> CHECK NULLPTR
        scene()->addItem(bullet);
    }
}
