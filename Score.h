#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QObject * parent=nullptr);
    void increase();
    int getScore();
private:
    int m_score;
};

#endif // SCORE_H
