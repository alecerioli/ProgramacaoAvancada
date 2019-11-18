#ifndef PLOTTER_H
#define PLOTTER_H
#include <QString>
#include <QWidget>
#include <QAction>
#include <QColor>
#include "sculptor.h"

class Plotter : public QWidget
{
    Q_OBJECT
private:
    int dimX,dimY,dimZ;
    int raio,raioX,raioY,raioZ,meia_largura,meia_altura,meia_espessura;
    int posX,posY,posZ;
    double altura,largura;
    int timerid;
    Sculptor *escultor;
    QString prox_acao;
    QColor cor;
    QAction *actionMessage;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
    void timerEvent(QTimerEvent *event);
    void setDimensoes(int x, int y, int z);
    void getProf(int zAtual);
    void getRaioEsfera(int raioAtual);
    void getRaioXElipsoide(int raioxAtual);
    void getRaioYElipsoide(int raioyAtual);
    void getRaioZElipsoide(int raiozAtual);
    void getLarguraCaixa(int largAtual);
    void getAlturaCaixa(int altAtual);
    void getEspessuraCaixa(int espAtual);
    void getCorVermelha(int redAtual);
    void getCorVerde(int greenAtual);
    void getCorAzul(int blueAtual);
    void colocaVoxel();
    void retiraVoxel();
    void colocaEsfera();
    void retiraEsfera();
    void colocaElipsoide();
    void retiraElipsoide();
    void colocaCaixa();
    void retiraCaixa();
signals:
    void mouseX(int);
    void mouseY(int);

public slots:
    void mostraMensagem();
};

#endif // PLOTTER_H
