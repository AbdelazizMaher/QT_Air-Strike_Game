#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health(QObject * parent=nullptr);
    void decrease();
    int getHealth();
private:
    int m_health;
signals:
    void healthDepleted();
};

#endif // HEALTH_H
