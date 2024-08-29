#include "Health.h"
#include <QFont>

Health::Health(QObject *parent)
{
    // initialize the health to 3
    m_health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(m_health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    if (m_health <= 0)
        emit healthDepleted();
    else
    {
        m_health--;
        setPlainText(QString("Health: ") + QString::number(m_health));
    }
}

int Health::getHealth()
{
    return m_health;
}
