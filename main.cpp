#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "Player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    Player * player1 = new Player();
    player1->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(player1);

    // make player1 focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    // visualize the scene
    view->show();

    return a.exec();
}
