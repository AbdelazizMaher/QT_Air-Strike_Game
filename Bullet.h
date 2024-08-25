#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();

public slots:
    void fireBullet();
};

#endif // BULLET_H
