#include "Score.h"
#include <QFont>

Score::Score(QObject *parent)
{
    // initialize the score to 0
    m_score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(m_score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    m_score++;
    setPlainText(QString("Score: ") + QString::number(m_score));
}

int Score::getScore()
{
    return m_score;
}
