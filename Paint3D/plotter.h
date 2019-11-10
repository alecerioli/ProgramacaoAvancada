#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QAction>
#include "sculptor.h"

class Plotter : public QWidget
{
    Q_OBJECT
private:
    int dimX,dimY,dimZ;
    Sculptor *escultor;
    QAction *actionMessage;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

    void setDimensoes(int x, int y, int z);
signals:
    void mouseX(int);
    void mouseY(int);

public slots:
    void mostraMensagem();
};

#endif // PLOTTER_H
