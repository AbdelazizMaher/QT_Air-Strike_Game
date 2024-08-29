#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>
#include <QBrush>
#include <QImage>
#include <QKeyEvent>

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    // Set focus on the Game view to handle key events
    this->setFocus();

    // create a scene
    m_scene = new QGraphicsScene(this);
    this->setScene(m_scene);
    setBackgroundBrush(QBrush(QImage(":/assets/images/background.jpg")));

    // create a player to put into the scene
    m_player = new Player(this);

    // add the player to the scene
    m_scene->addItem(m_player);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setFixedSize(800, 600);
    m_scene->setSceneRect(0, 0, 800, 600);
    m_player->setPos(this->width() / 2 - 50, this->height() - 100);

    // create the score/health
    m_score = new Score(this);
    m_score->setPos(m_score->x(), m_score->y() + 25);
    m_scene->addItem(m_score);

    m_health = new Health(this);
    m_health->setPos(m_health->x(), m_health->y() + 50);
    m_scene->addItem(m_health);

    connect(m_player, &Player::bulletFired, this, &Game::onBulletFired);
    connect(m_health, &Health::healthDepleted, this, &Game::onHealthDepleted);

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::spawnEnemy);
    timer->start(2000);

    // play background music
    QMediaPlayer * audioPlayer = new QMediaPlayer(this);
    QAudioOutput * audioOutput = new QAudioOutput(this);

    audioPlayer->setAudioOutput(audioOutput);
    audioPlayer->setSource(QUrl("qrc:/assets/audio/ObservingTheStar.ogg"));
    audioOutput->setVolume(50);
    audioPlayer->play();

    m_bulletSound = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);

    m_bulletSound->setAudioOutput(m_audioOutput);
    m_bulletSound->setSource(QUrl("qrc:/assets/audio/explosion.wav"));
    m_audioOutput->setVolume(50);

    // visualize the scene
    this->show();
}

void Game::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left)
        m_player->moveLeft();
    else if (event->key() == Qt::Key_Right)
        m_player->moveRight();
    else if (event->key() == Qt::Key_Space)
    {
        m_player->fireBullet();
        handleBulletSound();
    }
}

void Game::spawnEnemy()
{
    Enemy * enemy = new Enemy();
    connect(enemy, &Enemy::enemyDestroyed, this, &Game::onEnemyDestroyed);
    scene()->addItem(enemy);
}

void Game::onEnemyDestroyed(Enemy *enemy, Enemy::DeathCause cause)
{
    if (cause == Enemy::DeathCause::OutOfScreen)
        m_health->decrease();
    else if (cause == Enemy::DeathCause::BulletCollision)
        m_score->increase();

    // Ensure the enemy is removed from the scene before deletion
    m_scene->removeItem(enemy);
    delete enemy;
}

void Game::onBulletFired()
{
    Bullet *bullet = new Bullet();

    bullet->setPos(m_player->x() + 70, m_player->y());

    connect(bullet, &Bullet::bulletDestroyed, this, &Game::onBulletDestroyed);
    connect(bullet, &Bullet::bulletCollided, this, &Game::onBulletCollided);

    m_scene->addItem(bullet);
}

void Game::onBulletCollided(QGraphicsItem *item1, Bullet *bullet)
{
    onEnemyDestroyed(dynamic_cast<Enemy*>(item1), Enemy::DeathCause::BulletCollision);
    onBulletDestroyed(bullet);
}

void Game::onBulletDestroyed(Bullet *bullet)
{
    m_scene->removeItem(bullet);
    delete bullet;
}

void Game::handleBulletSound()
{
    if (m_bulletSound->playbackState() == QMediaPlayer::PlayingState)
        m_bulletSound->setPosition(0);
    else
        m_bulletSound->play();
}

void Game::onHealthDepleted()
{
    // Display "Game Over" text in white
    QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
    QFont font("times", 50);
    gameOverText->setFont(font);
    gameOverText->setDefaultTextColor(Qt::white);
    gameOverText->setPos(this->width() / 2 - gameOverText->boundingRect().width() / 2,
                         this->height() / 2 - gameOverText->boundingRect().height() / 2);

    m_scene->addItem(gameOverText);
}
