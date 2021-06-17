#include "myview.h"

myview::myview(QWidget * parent) : QGraphicsView(parent)
{
    setMinimumSize(1100,740);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setCacheMode(QGraphicsView::CacheBackground);
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setContentsMargins(0,0,0,0);
    setContentsMargins(0,0,0,0);

}

void myview::sceneSet(QGraphicsScene * scene)
{
    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
