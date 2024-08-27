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
    Player(QGraphicsItem *parent= nullptr);

    void keyPressEvent(QKeyEvent * event) override;

private:
    QMediaPlayer * bulletSound;
    QAudioOutput * audioOutput;
public slots:
    void spawnEnemy();
};

#endif // PLAYER_H
