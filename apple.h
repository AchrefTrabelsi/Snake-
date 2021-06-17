#ifndef APPLE_H
#define APPLE_H
#include <QGraphicsItem>
#include <QPixmap>


class apple : public QGraphicsItem
{
public:
    apple(QGraphicsItem * parent = nullptr);
    QRectF boundingRect() const override;
    void updatepos();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private:
    QPixmap im;
};

#endif // APPLE_H
