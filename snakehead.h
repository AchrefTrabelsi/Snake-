#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H
#include <QGraphicsItem>
#include <QPointF>


class SnakeHead : public QGraphicsItem
{

public:
    SnakeHead(QGraphicsItem * parent = nullptr);
    void setdir(const QPointF &);
    void setspeed(float const &);
    QPointF getdir();

protected:
    QRectF boundingRect() const override;
    void advance(int phase) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private:
    QPointF dir;
    QPointF speed;
    QPixmap im;
    bool draw;
    bool temp;
};

#endif // SNAKEHEAD_H
