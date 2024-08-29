#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"
#include "Bullet.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=nullptr);

    QGraphicsScene * m_scene;
    Player * m_player;
    Score * m_score;
    Health * m_health;
protected:
    void keyPressEvent(QKeyEvent *event) override;
    QMediaPlayer * m_bulletSound;
    QAudioOutput * m_audioOutput;
public slots:
    void onBulletFired();
    void onBulletCollided(QGraphicsItem *item1, Bullet *bullet);
    void onBulletDestroyed(Bullet *bullet);
    void handleBulletSound();

    void spawnEnemy();
    void onEnemyDestroyed(Enemy *enemy, Enemy::DeathCause cause);

    void onHealthDepleted();
};

#endif // GAME_H
