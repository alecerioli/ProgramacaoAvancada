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
    dimX=dimY=dimZ=30;
    prox_acao="";
    raio=raioX=raioY=raioZ=0;
    meia_altura=meia_largura=meia_espessura=0;
    posZ=0;
    timerid = startTimer(10);
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
    altura = (double)height()/dimX;
    largura = (double)width()/dimY;
    pen.setWidth(2);
    painter.setPen(pen);
    for (int i=1;i<=dimX;i++){
        painter.drawLine(0,i*altura,width(),i*altura);
    }
    for (int i=1;i<=dimY;i++){
        painter.drawLine(i*largura,0,i*largura,height());
    }
    // Voxel pintados
    for(int i=0;i<dimX;i++){
        for(int j=0;j<dimY;j++){
            if(escultor->v[i][j][posZ].isOn==true){
                int pos_linha = i*altura;
                int pos_coluna = j*largura;
                float cor_r=(escultor->v[i][j][posZ].r)*255.0;
                float cor_g=(escultor->v[i][j][posZ].g)*255.0;
                float cor_b=(escultor->v[i][j][posZ].b)*255.0;
                brush.setColor(QColor(211, 215, 207));
                painter.setBrush(brush);
                painter.drawRect(pos_coluna,pos_linha,largura,altura);
                brush.setColor(QColor(cor_r,cor_g,cor_b));
                painter.setBrush(brush);
                painter.drawEllipse(pos_coluna,pos_linha,largura,altura);
            }
        }
    }
}


void Plotter::mousePressEvent(QMouseEvent *event)
{
    int x, y;
    x = event->x();
    y = event->y();
    qDebug() << x << y;
    qDebug() << event->button();
    emit mouseX(x);
    emit mouseY(y);
    posY=x/largura;
    posX=y/altura;
    escultor->setColor(cor.red()/255,cor.green()/255,cor.blue()/255,1);
    if(prox_acao=="putvoxel"){
        escultor->putVoxel(posX,posY,posZ);
    }
    if(prox_acao=="cutvoxel"){
        escultor->cutVoxel(posX,posY,posZ);
    }
    if(prox_acao=="putsphere"){
        escultor->putSphere(posX,posY,posZ,raio);
    }
    if(prox_acao=="cutsphere"){
        escultor->cutSphere(posX,posY,posZ,raio);
    }
    if(prox_acao=="putellipsoid"){
        escultor->putEllipsoid(posX,posY,posZ,raioX,raioY,raioZ);
    }
    if(prox_acao=="cutellipsoid"){
        escultor->cutEllipsoid(posX,posY,posZ,raioX,raioY,raioZ);
    }
    if(prox_acao=="putbox"){
        escultor->putBox(posX-meia_largura,posX+meia_largura,posY-meia_altura,posY+meia_altura,posZ-meia_espessura,posZ+meia_espessura);
    }
    if(prox_acao=="cutbox"){
        escultor->cutBox(posX-meia_largura,posX+meia_largura,posY-meia_altura,posY+meia_altura,posZ-meia_espessura,posZ+meia_espessura);
    }
}


void Plotter::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(actionMessage);
    menu.exec(event->globalPos());
}

void Plotter::timerEvent(QTimerEvent *event)
{
    int id;
    id = event->timerId();
    repaint();
}

void Plotter::setDimensoes(int x, int y, int z)
{
    dimX = x;  dimY = y; dimZ = z;
    escultor = new Sculptor(dimX,dimY,dimZ);
    repaint();
}

void Plotter::getProf(int zAtual)
{
    posZ=zAtual;
}

void Plotter::getRaioEsfera(int raioAtual)
{
    raio=raioAtual;
}

void Plotter::getRaioXElipsoide(int raioxAtual)
{
    raioX=raioxAtual;
}

void Plotter::getRaioYElipsoide(int raioyAtual)
{
    raioY=raioyAtual;
}

void Plotter::getRaioZElipsoide(int raiozAtual)
{
    raioZ=raiozAtual;
}

void Plotter::getLarguraCaixa(int largAtual)
{
    meia_largura=largAtual;
}

void Plotter::getAlturaCaixa(int altAtual)
{
    meia_altura=altAtual;
}

void Plotter::getEspessuraCaixa(int espAtual)
{
    meia_espessura=espAtual;
}

void Plotter::getCorVermelha(int redAtual)
{
    cor.setRed(redAtual);
}

void Plotter::getCorVerde(int greenAtual)
{
    cor.setGreen(greenAtual);
}

void Plotter::getCorAzul(int blueAtual)
{
    cor.setBlue(blueAtual);
}

void Plotter::colocaVoxel()
{
    prox_acao="putvoxel";
    qDebug() <<prox_acao;
}

void Plotter::retiraVoxel()
{
    prox_acao="cutvoxel";
    qDebug() <<prox_acao;
}

void Plotter::colocaEsfera()
{
    prox_acao="putsphere";
    qDebug() <<prox_acao;
}

void Plotter::retiraEsfera()
{
    prox_acao="cutsphere";
    qDebug() <<prox_acao;
}

void Plotter::colocaElipsoide()
{
    prox_acao="putellipsoid";
    qDebug() <<prox_acao;
}

void Plotter::retiraElipsoide()
{
    prox_acao="cutellipsoid";
    qDebug() <<prox_acao;
}

void Plotter::colocaCaixa()
{
    prox_acao="putbox";
    qDebug() <<prox_acao;
}

void Plotter::retiraCaixa()
{
    prox_acao="cutbox";
    qDebug() <<prox_acao;
}

void Plotter::mostraMensagem()
{
    QMessageBox box;
    box.setText("Alo, menu!");
    box.exec();
}





