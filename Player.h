#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player() = default;

    void keyPressEvent(QKeyEvent * event) override;
public slots:
    void spawnEnemy();
};

#endif // PLAYER_H
