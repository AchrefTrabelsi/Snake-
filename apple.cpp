#include "apple.h"
#include <QPainter>
#include <QTime>

apple::apple(QGraphicsItem * parent) : QGraphicsItem(parent)
{
    im = QPixmap(":snake/apple.png");
    qsrand(QTime::currentTime().second());
}

QRectF apple::boundingRect() const
{
    return QRectF(0,0,40,40);
}

void apple::updatepos()
{
    do
    {
        int nx =qrand()%20;
        int ny = qrand()%18;
        setPos(10+nx*40,10+ny*40);
    }
    while (collidingItems().size()>1);
}

void apple::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF a = boundingRect();
    painter->drawPixmap(a.x(),a.y(),a.width(),a.height(),im);

}
