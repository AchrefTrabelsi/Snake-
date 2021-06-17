#include "snaketail.h"
#include <QPainter>




SnakeTail::SnakeTail(int x , int y ,int model ,QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setPos(x,y);
    QPixmap im = QPixmap(":snake/snakehead.png");
    rl = im.copy(43,1,40,40);
    imv = im.copy(85,85,40,40);
    tail= im.copy(43,85,40,40);
    this->model=model;

}

void SnakeTail::setmodel(int m)
{
    model=m;
}
int SnakeTail::getmodel()
{
    return model;
}

void SnakeTail::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF r =boundingRect();
    QTransform t ;
    if(model>=lowtoright)
    {
        t.rotate(90*(model-lowtoright));
        painter->drawPixmap(r.x(),r.y(),r.width(),r.height(),rl.transformed(t));
    }
    else if(model>=0)
    {
        t.rotate(90*(model-vtail));
        painter->drawPixmap(r.x(),r.y(),r.width(),r.height(),imv.transformed(t));

    }
    else
    {
        t.rotate(90*(-1-model));
        painter->drawPixmap(r.x(),r.y(),r.width(),r.height(),tail.transformed(t));

    }



}
QRectF SnakeTail::boundingRect() const
{
    return QRectF(0,0,40,40);
}

