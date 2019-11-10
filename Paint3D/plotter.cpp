#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include "sculptor.h"

using namespace std;

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    dimX=30;
    dimY=30;
    dimZ=30;
    escultor = new Sculptor(dimX,dimY,dimZ);
    setMouseTracking(true);
    actionMessage = new QAction(this);
    actionMessage->setText("mostra mensagem");
    connect(actionMessage,
            SIGNAL(triggered()),
            this,
            SLOT(mostraMensagem()));
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing);
    // Configurando o preenchimento da area de desenho
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    // Configrando o Contorno da área de desenho
    pen.setColor(QColor(0,0,0));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);

    // Area de desenho
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0,0,width(),height());
    int h_altura = (double)height()/dimX;
    int h_largura = (double)width()/dimY;
    pen.setWidth(2);
    painter.setPen(pen);
    for (int i=1;i<=dimX;i++){
        painter.drawLine(0,i*h_altura,width(),i*h_altura);
    }
    for (int i=1;i<=dimY;i++){
        painter.drawLine(i*h_largura,0,i*h_largura,height());
    }
}


void Plotter::mousePressEvent(QMouseEvent *event)
{
    int x, y;
    x = event->x();
    y = event->y();
    //  qDebug() << x << y;
    //  qDebug() << event->button();
    emit mouseX(x);
    emit mouseY(y);
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseX(event->x());
    emit mouseY(event->y());
}

void Plotter::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(actionMessage);
    menu.exec(event->globalPos());
}

void Plotter::setDimensoes(int x, int y, int z)
{
    dimX = x;  dimY = y; dimZ = z;
    repaint();
}


void Plotter::mostraMensagem()
{
    QMessageBox box;
    box.setText("Alo, menu!");
    box.exec();
}





