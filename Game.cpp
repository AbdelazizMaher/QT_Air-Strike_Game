#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>

Game::Game()
{
    // create a scene
    m_scene = new QGraphicsScene();
    this->setScene(m_scene);

    // create an item to put into the scene
    m_player = new Player();
    m_player->setRect(0, 0, 100, 100);

    // add the item to the scene
    m_scene->addItem(m_player);

    // make player1 focusable
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setFixedSize(800, 600);
    m_scene->setSceneRect(0, 0, 800, 600);
    m_player->setPos(this->width() / 2 - m_player->rect().width()/2, this->height() - m_player->rect().height());

    // create the score/health
    m_score = new Score();
    m_score->setPos(m_score->x(), m_score->y() + 25);
    m_scene->addItem(m_score);

    m_health = new Health();
    m_health->setPos(m_health->x(), m_health->y() + 50);
    m_scene->addItem(m_health);

    QTimer * timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, m_player, &Player::spawnEnemy);
    timer->start(2000);

    // play background music
    QMediaPlayer * bg_music = new QMediaPlayer();
    bg_music->setSource(QUrl("qrc:/assets/audio/ObservingTheStar.wav"));
    bg_music->play();

    // visualize the scene
    this->show();


}
