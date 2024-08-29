#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QObject *parent)
{
    setPixmap(QPixmap(":/assets/images/P38_lvl_3_d1.png"));
}

void Player::moveLeft()
{
    if (x() > 0)
        setPos(x() - 10, y());
}

void Player::moveRight()
{
    if (x() + 100 < 800)
        setPos(x() + 10, y());
}

void Player::fireBullet()
{
    emit bulletFired();
}

