#ifndef PLOTTER_H
#define PLOTTER_H
#include <QString>
#include <QWidget>
#include <QAction>
#include <QColor>
#include <cstring>
#include "sculptor.h"

/**
 * @brief A classe Plotter
 * representa o conjunto area-pintor do escultor 3D que será mostrado na MainWindow.
 * Consiste no plano XY que pode ser alterado em profundidade e em figuras.
 */
class Plotter : public QWidget
{
    Q_OBJECT
private:
    /**
     * @brief dimX: dimensao X (numero de linhas).
     */
    int dimX;
    /**
     * @brief dimY: dimensao Y (numero de colunas).
     */
    int dimY;
    /**
     * @brief dimZ: dimensao Z (numero de planos).
     */
    int dimZ;
    /**
     * @brief raio: raio da esfera que será colocada.
     */
    int raio;
    /**
     * @brief raioX: raio X da elipsoide que será colocada.
     */
    int raioX;
    /**
     * @brief raioY: raio Y da elipsoide que será colocada.
     */
    int raioY;
    /**
     * @brief raioZ: raio Z da elipsoide que será colocada.
     */
    int raioZ;
    /**
     * @brief meia_largura: meia largura da caixa que será colocada.
     */
    int meia_largura;
    /**
     * @brief meia_altura: meia altura da caixa que será colocada.
     */
    int meia_altura;
    /**
     * @brief meia_espessura: meia espessura da caixa que será colocada.
     */
    int meia_espessura;
    /**
     * @brief posX: indice X do escultor.
     */
    int posX;
    /**
     * @brief posY: indice Y do escultor.
     */
    int posY;
    /**
     * @brief posZ: indice Z do escultor.
     */
    int posZ;
    /**
     * @brief altura: espaco entre as linhas da area de desenho.
     */
    double altura;
    /**
     * @brief largura: espaco entre as colunas da area de desenho.
     */
    double largura;
    /**
     * @brief timerid: temporizador.
     */
    int timerid;
    /**
     * @brief filename: endereco onde será salvo o arquivo OFF.
     */
    std::string filename;
    /**
     * @brief nomeArquivo: endereco retornado da caixa de dialogo que salva o arquivo OFF (QFileDialog).
     */
    QString nomeArquivo;
    /**
     * @brief escultor: ponteiro para o escultor.
     */
    Sculptor *escultor;
    /**
     * @brief prox_acao: proxima acão que será executada na hora do click.
     */
    QString prox_acao;
    /**
     * @brief cor: cor do desenho.
     */
    QColor cor;
    /**
     * @brief actionMessage: ponteiro de uma mensagem devido a uma acão.
     */
    QAction *actionMessage;

public:
    /**
     * @brief Plotter eh o construtor da classe Plotter.
     * @param parent : parametro geralmente nulo.
     */
    explicit Plotter(QWidget *parent = nullptr);
    /**
     * @brief paintEvent eh o metodo responsavel por desenhar na area de desenho.
     * @param event : evento relacionado ao desenho.
     */
    void paintEvent(QPaintEvent *event);
    /**
     * @brief mousePressEvent eh o metodo responsavel por detectar clicks esquerdos e capturar a posicao.
     * @param event : evento relacionado ao click esquerdo.
     */
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief contextMenuEvent eh o metodo responsavel por mostrar uma mensagem se hover um click direito.
     * @param event : evento relacionado ao click direito.
     */
    void contextMenuEvent(QContextMenuEvent *event);
    /**
     * @brief timerEvent eh o metodo responsavel por redesenhar o escultor a cada passagem de tempo.
     * @param event : evento relacionado ao tempo.
     */
    void timerEvent(QTimerEvent *event);
    /**
     * @brief setDimensoes eh um metodo que guarda as dimensoes e cria um escultor com essas dimensoes.
     * @param x : futura dimensao X.
     * @param y : futura dimensao Y.
     * @param z : futura dimensao Z.
     */
    void setDimensoes(int x, int y, int z);
    /**
     * @brief salva eh um metodo que salva a escultura no formato OFF.
     */
    void salva();
    /**
     * @brief novo eh um metodo que cria um novo escultor.
     */
    void novo();
    /**
     * @brief outrasCores eh um metodo que abre uma caixa de dialogo para escolher a cor (QCorDialog).
     */
    void outrasCores();
    /**
     * @brief abrirComMeshLab eh um metodo que abre o escultor no programa MeshLab.
     */
    void abrirComMeshLab();
    /**
     * @brief getProf eh uma funcao que guarda a profundidade atual.
     * @param zAtual : profundidade atual.
     */
    void getProf(int zAtual);
    /**
     * @brief getRaioEsfera eh uma funcao que guarda o raio da esfera que será colocada.
     * @param raioAtual : raio atual da esfera que será colocada.
     */
    void getRaioEsfera(int raioAtual);
    /**
     * @brief getRaioXElipsoide eh uma funcao que guarda o raio X da elipsoide que será colocada.
     * @param raioxAtual : raio X atual da elipsoide que será colocada.
     */
    void getRaioXElipsoide(int raioxAtual);
    /**
     * @brief getRaioYElipsoide eh uma funcao que guarda o raio Y da elipsoide que será colocada.
     * @param raioyAtual : raio Y atual da elispoide que será colocada.
     */
    void getRaioYElipsoide(int raioyAtual);
    /**
     * @brief getRaioZElipsoide eh uma funcao que guarda o raio Z da elipsoide que será colocada.
     * @param raiozAtual : raio Z atual da elipsoide que será colocada.
     */
    void getRaioZElipsoide(int raiozAtual);
    /**
     * @brief getLarguraCaixa eh uma funcao que guarda metade da largura da caixa que será colocada.
     * @param largAtual : meia largura atual da caixa que será colocada.
     */
    void getLarguraCaixa(int largAtual);
    /**
     * @brief getAlturaCaixa eh uma funcao que guarda metade da altura da caixa que será colocada.
     * @param altAtual : meia altura atual da caixa que será colocada.
     */
    void getAlturaCaixa(int altAtual);
    /**
     * @brief getEspessuraCaixa eh uma funcao que guarda metade da espessura da caixa que será colocada.
     * @param espAtual : meia espessura atual da caixa que será colocada.
     */
    void getEspessuraCaixa(int espAtual);
    /**
     * @brief getCorVermelha eh uma funcao que guarda a intensidade da cor vermelha do desenho.
     * @param redAtual: intensidade da cor vermelha atual.
     */
    void getCorVermelha(int redAtual);
    /**
     * @brief getCorVerde eh uma funcao que guarda a intensidade da cor verde do desenho.
     * @param greenAtual: intensidade da cor verde atual.
     */
    void getCorVerde(int greenAtual);
    /**
     * @brief getCorAzul eh uma funcao que guarda a intensidade da cor azul do desenho.
     * @param blueAtual: intensidade da cor azul atual.
     */
    void getCorAzul(int blueAtual);
    /**
     * @brief colocaVoxel eh um metodo que define a proxima acão como sendo "putvoxel".
     */
    void colocaVoxel();
    /**
     * @brief retiraVoxel eh um metodo que define a proxima acão como sendo "cutvoxel".
     */
    void retiraVoxel();
    /**
     * @brief colocaEsfera eh um metodo que define a proxima acão como sendo "putsphere".
     */
    void colocaEsfera();
    /**
     * @brief retiraEsfera eh um metodo que define a proxima acão como sendo "cutvoxel".
     */
    void retiraEsfera();
    /**
     * @brief colocaElipsoide eh um metodo que define a proxima acão como sendo "putellipsoid".
     */
    void colocaElipsoide();
    /**
     * @brief retiraElipsoide eh um metodo que define a proxima acão como sendo "cutellipsoid".
     */
    void retiraElipsoide();
    /**
     * @brief colocaCaixa eh um metodo que define a proxima acão como sendo "putbox".
     */
    void colocaCaixa();
    /**
     * @brief retiraCaixa eh um metodo que define a proxima acão como sendo "cutbox".
     */
    void retiraCaixa();
signals:
    /**
     * @brief mouseX : sinal emitido que informa a posicao X do click esquerdo.
     */
    void mouseX(int);
    /**
     * @brief mouseY : sinal emitido que informa a posicao Y do click esquerdo.
     */
    void mouseY(int);
    /**
     * @brief alteraSliderR : sinal emitido para alterar o slide referente a intensidade da cor vermelha.
     */
    void alteraSliderR(int);
    /**
     * @brief alteraSliderG : sinal emitido para alterar o slide referente a intensidade da cor verde.
     */
    void alteraSliderG(int);
    /**
     * @brief alteraSliderB : sinal emitido para alterar o slide referente a intensidade da cor azul.
     */
    void alteraSliderB(int);
public slots:
    /**
     * @brief mostraMensagem serve para mostrar uma mensagem se hover um click direito.
     */
    void mostraMensagem();
};

#endif // PLOTTER_H
