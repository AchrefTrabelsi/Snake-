#include "snakehead.h"
#include <QPainter>
#include <QKeyEvent>
#include <QPixmap>
#define right QPointF(1,0)
#define left QPointF(-1,0)
#define up QPointF(0,-1)
#define down QPointF(0,1)


SnakeHead::SnakeHead(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    speed.setX(40);
    speed.setY(40);

    setPos(800/2,600/2);
    setdir(up);
    im = QPixmap(":snake/snakehead.png");
    im =im.copy(0,2,42,40);
    draw = true;
}
QPointF SnakeHead::getdir()
{
    return dir;
}


void SnakeHead::setdir(const QPointF &d)
{
    dir =d;
}


void SnakeHead::setspeed(const float &s)
{
    speed =speed*s;
}


QRectF SnakeHead::boundingRect() const
{
    return QRectF(0,0,40,40);
}

void SnakeHead::advance(int phase)
{
    if(!phase) return ;
    setPos(mapToParent(dir.x()*speed.x(),dir.y()*speed.y()));
    draw = true;
}

void SnakeHead::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(!draw) return;

    QRectF r =boundingRect();
     QTransform t ;
     if(dir == up)
        t= t.rotate(180);
     if(dir == right)
        t= t.rotate(270);
     if(dir == left)
        t= t.rotate(90);
     if(dir == down)
        t= t.rotate(0);
    painter->drawPixmap(r.x(),r.y(),r.width(),r.height(),im.transformed(t));
    draw=false;
}

