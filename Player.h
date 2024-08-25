#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class Player : public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent * event) override;
};

#endif // PLAYER_H
