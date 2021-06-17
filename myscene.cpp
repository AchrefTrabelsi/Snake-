#include "myscene.h"
#include <QKeyEvent>
#define right QPointF(1,0)
#define left QPointF(-1,0)
#define up QPointF(0,-1)
#define down QPointF(0,1)
#define w 5


myscene::myscene(QObject * parent) : QGraphicsScene(0,0,1100,740,parent)
{
    setBackgroundBrush(QBrush(QColor(255,255,255)));
    QPen l(QBrush(QColor(255,0,0)),10);
    addLine(w,w,w,740-w,l);
    addLine(w,w,820,w,l);
    addLine(w,740-w,820,740-w,l);
    addLine(820,w,820,740-w,l);
    rscore=0;
    QFont t;
    bg = new QGraphicsPixmapItem(QPixmap(":snake/bg.jpg").scaled(805,720));
    bg->setPos(10,10);
    addItem(bg);
    t.setPixelSize(30);
    score = addText("",t);
    updatescore();
    score->setPos(880,40);
    restart = false;
    add = false;
    myapple = new apple();
    myapple->updatepos();
    addItem(myapple);
    head = new SnakeHead();
    head->setPos(410,370);
    nxp = head->pos();
    d=head->getdir();
    nd = d;
    addItem(head);
   // this->setFlag(QGraphicsItem::ItemIsFocusable);
   // head->setFocus();
    size = 0;



}

int myscene::newmodel()
{
    QPointF cdir = head->getdir();
    float sm;
    if(cdir==d)
    {
        sm=abs(cdir.x()*d.x());
    }
    else
    {
        if(cdir==down)
            sm=5.5+d.x()*0.5;
        if(cdir==up)
            sm=7.5 - d.x()*0.5;
        if(cdir==left)
            sm=6.5 + d.y()*0.5;
        if(cdir == right)
            sm=6.5 + 1.5*d.y();



    }
    return sm;

}

void myscene::gamestatus()
{
    for(int i=0;i<size;i++)
        if(head->pos()==tail[i]->pos())
        {
            emit gameover();
            restart=true;
            gameovertext();
            return;
        }
    if(head->pos().x()>770 || head->pos().x()<10)
    {
        emit gameover();
        gameovertext();
        restart=true;
        return;
    }
    if(head->pos().y()>690 || head->pos().y()<10)
    {
        emit gameover();
        gameovertext();
        restart=true;
        return;
    }
    if(head->pos()==myapple->pos()) add= true;

}

int myscene::tailmodel()
{
    QPointF cdir = head->getdir();
    if(cdir == up)
        return bottomtotop;
    if(cdir==down)
        return toptobottom;
    if(cdir==left)
        return righttoleft;
    if(cdir == right)
        return lefttoright;
    return  0;
}

void myscene::nextframe()
{   gamestatus();
    if(add)
    {
        rscore+=100;
        updatescore();
        int ms = tail.empty() ? tailmodel() : newmodel();
        tail.push_front(new SnakeTail(nxp.x(),nxp.y(),ms));
        addItem(tail[0]);
        size++;
        add = false;
        myapple->updatepos();
    }
    else
    {
        for(int i=size-1;i>0;i--)
        {
            tail[i]->setPos(tail[i-1]->pos());
            tail[i]->setmodel(tail[i-1]->getmodel());
        }
        if(size==1)
        {
            tail[0]->setPos(nxp);
            tail[0]->setmodel(tailmodel());
        }
        else
        if(size>1)
        {
        tail[0]->setPos(nxp);
        tail[0]->setmodel(newmodel());
        QPointF p = tail[size-2]->pos();
        QPointF p2 = tail[size-1]->pos();

        if(p.x()-p2.x()>0)
        {
            tail[size-1]->setmodel(lefttoright);
        }
        if(p.x()-p2.x()<0)
        {
            tail[size-1]->setmodel(righttoleft);
        }
        if(p.y()-p2.y()>0)
        {
            tail[size-1]->setmodel(toptobottom);
        }
        if(p.y()-p2.y()<0)
        {
            tail[size-1]->setmodel(bottomtotop);
        }




        }
    }
    nxp =head->pos();
    d=nd;
}
void myscene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_F11) emit chsize();
    if(restart  && event->key() == Qt::Key_Return)
    {
        emit reset();
        return;
    }
    if(event->key()==Qt::Key_Left && d != right)
        nd=left;
    if(event->key()==Qt::Key_Right && d != left)
        nd=right;
    if(event->key()==Qt::Key_Up && d != down)
        nd=up;
    if(event->key()==Qt::Key_Down && d != up)
        nd=down;
    head->setdir(nd);

}

void myscene::updatescore()
{
    score->setPlainText("Score : "+QString::number(rscore));
}

void myscene::gameovertext()
{
    QFont t;
    t.setPixelSize(25);
    addText("Press Enter To Restart",t)->setPos(830,340);

}





