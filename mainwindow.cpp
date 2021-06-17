#include "mainwindow.h"
#include "QTimer"
#include <QThread>
#include<QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    scene = new myscene(this);
    view = new myview(this);
    view->sceneSet(scene);
    setMinimumSize(1100,740);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,&QTimer::timeout,scene,&myscene::nextframe);
    connect(scene,&myscene::gameover,timer,&QTimer::stop);
    connect(scene,&myscene::reset,this,&MainWindow::restart);
    connect(scene,&myscene::chsize,[&]{if(isFullScreen()==false) showFullScreen();else showNormal();});
    timer->start(1000/6);


}

void MainWindow::restart()
{
    delete scene;
    scene = new myscene(this);
    view->sceneSet(scene);
    timer->start(1000/5);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,&QTimer::timeout,scene,&myscene::nextframe);
    connect(scene,&myscene::gameover,timer,&QTimer::stop);
    connect(scene,&myscene::reset,this,&MainWindow::restart);
    connect(scene,&myscene::chsize,[&]{if(isFullScreen()==false) showFullScreen();else showNormal();});


}


