#ifndef SNAKETAIL_H
#define SNAKETAIL_H
#include <QGraphicsItem>
#include <QPointF>

#define lowtoright 5
#define lowtoleft 6
#define lefttohigh 7
#define righttohigh 8
#define vtail 0
#define htail 1
#define lefttoright -2
#define righttoleft -4
#define toptobottom -3
#define bottomtotop -1


class SnakeTail : public QGraphicsItem
{
public:
    SnakeTail(int x =0,int y =0,int model =0,QGraphicsItem * parent = nullptr);
    void setmodel(int m);
    QPixmap imv;
    QPixmap rl;
    QPixmap tail;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    int getmodel();

protected:
    QRectF boundingRect() const override;

private:
    int model;

};


#endif // SNAKETAIL_H
