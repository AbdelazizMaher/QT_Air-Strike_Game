#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game : public QGraphicsView
{
public:
    Game();

    QGraphicsScene * m_scene;
    Player * m_player;
    Score * m_score;
    Health * m_health;
};

#endif // GAME_H
