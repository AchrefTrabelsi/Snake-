#ifndef MYSCENE_H
#define MYSCENE_H
#include<QGraphicsScene>
#include "snakehead.h"
#include "snaketail.h"
#include "apple.h"




class myscene : public QGraphicsScene
{
    Q_OBJECT
public:
    myscene(QObject * parent );
    int newmodel();
    void gamestatus();
    int tailmodel();
    void keyPressEvent(QKeyEvent *event) override;
    void updatescore();
    void gameovertext();
private:
    SnakeHead * head;
    QList<SnakeTail *> tail;
    apple * myapple;
    int size;
    QPointF d,nd;
    QPointF nxp;
    bool restart;
    bool add;
    QGraphicsPixmapItem * bg;
    qint64 rscore;
    QGraphicsTextItem * score;

public slots:
    void nextframe();
signals:
    void gameover();
    void reset();
    void draw();
    void chsize();

};

#endif // MYSCENE_H
