#include "Enemy.h"
#include "Game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <random>

Enemy::Enemy(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    std::random_device rd;
    std::mt19937 mt{ rd() };
    std::uniform_int_distribution<> dis(0, 700);

    // Set random position
    int random_number = dis(mt);
    setPos(random_number, 0);

    setPixmap(QPixmap(":/assets/images/Aircraft_06.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemy::moveDown);

    timer->start(50);
}

void Enemy::moveDown()
{
    setPos(x(), y() + 5);
    if (y() >= 600)
        emit enemyDestroyed(this, DeathCause::OutOfScreen);
}
