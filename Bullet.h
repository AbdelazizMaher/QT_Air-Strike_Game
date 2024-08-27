#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent= nullptr);

public slots:
    void fireBullet();
};

#endif // BULLET_H
