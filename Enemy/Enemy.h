#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum class DeathCause
    {
        OutOfScreen,
        BulletCollision
    };

    Enemy(QGraphicsItem *parent= nullptr);
signals:
    void enemyDestroyed(Enemy *enemy, DeathCause cause);
public slots:
    void moveDown();
};

#endif // ENEMY_H
