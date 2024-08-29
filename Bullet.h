#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent= nullptr);
signals:
    void bulletCollided(QGraphicsItem *item1, Bullet *bullet);
    void bulletDestroyed(Bullet* bullet);
public slots:
    void onFireTimeout();
};

#endif // BULLET_H
