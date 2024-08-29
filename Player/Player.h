#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QObject *parent= nullptr);
    void moveLeft();
    void moveRight();
    void fireBullet();

signals:
    void bulletFired();
};

#endif // PLAYER_H
