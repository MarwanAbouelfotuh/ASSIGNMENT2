#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"
#include <QDebug>
extern Game * game;

Enemy::Enemy(): QObject(),  QGraphicsPixmapItem(){

    int random_number = rand() % 700;
    setPos(random_number,0);


    setPixmap(QPixmap(":/new/prefix1/chick.png").scaled(100, 100));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){

    setPos(x(),y()+5);
    if (pos().y() + boundingRect().height() < 0){

        scene()->removeItem(this);
        delete this;
    }
    if (pos().y() > 600){

        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
