#include "Enemy.h"
#include "Game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <random>

extern Game * game; // there is an external global object called game

Enemy::Enemy()
{
    std::random_device rd;
    std::mt19937 mt{ rd() };
    std::uniform_int_distribution<> dis(0, 700);

    // Set random position
    int random_number = dis(mt);
    setPos(random_number, 0);

    // drew the rect
    setRect(0,0,100,100);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemy::moveDown);

    timer->start(50);
}

void Enemy::moveDown()
{
    setPos(x(), y() + 5);
    if (y() + rect().height() >= 800)
    {
        game->m_health->decrease();

        //TODO --->> CHECK NULLPTR
        scene()->removeItem(this);
        // TODO not best practice
        delete this;
    }
}
