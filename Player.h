#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();

    void keyPressEvent(QKeyEvent * event) override;

private:
    QMediaPlayer * bulletSound;
    QAudioOutput * audioOutput;
public slots:
    void spawnEnemy();
};

#endif // PLAYER_H
