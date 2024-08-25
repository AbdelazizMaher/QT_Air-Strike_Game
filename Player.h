#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class Player : public QGraphicsRectItem
{
public:
    Player() = default;

    void keyPressEvent(QKeyEvent * event) override;
};

#endif // PLAYER_H
