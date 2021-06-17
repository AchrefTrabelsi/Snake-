#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>


class myview : public QGraphicsView
{
    Q_OBJECT
public:
    myview(QWidget * parent);
    void sceneSet(QGraphicsScene *);

};

#endif // MYVIEW_H
