#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "myview.h"
#include "myscene.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);    
    void execute();

signals:
private:
    int h;
    int w;
    myscene * scene;
    myview * view;
    QTimer * timer;
public slots:
    void restart();

};

#endif // MAINWINDOW_H
