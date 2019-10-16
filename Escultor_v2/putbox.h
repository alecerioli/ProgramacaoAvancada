#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe PutBox
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Coloca uma caixa de voxel com coordenadas e cor definidas.
 */
class PutBox : public FiguraGeometrica{
    /**
     * @brief x0 : coordenada x inicial.
     */
    int x0;
    /**
     * @brief x1 : coordenada x final.
     */
    int x1;
    /**
     * @brief y0 : coordenada y inicial.
     */
    int y0;
    /**
     * @brief y1 : coordenada y final.
     */
    int y1;
    /**
     * @brief z0 : coordenada z final.
     */
    int z0;
    /**
     * @brief z1 : coordenada z final.
     */
    int z1;
public:
    /**
     * @brief PutBox eh o construtor da classe PutBox.
     * @param x0 : coordenada x inicial.
     * @param x1 : coordenada x final.
     * @param y0 : coordenada y inicial.
     * @param y1 : coordenada y final.
     * @param z0 : coordenada z inicial.
     * @param z1 : coordenada z final.
     * @param r : intensidade da cor vermelha (entre 0 e 1).
     * @param g : intensidade da cor verde (entre 0 e 1).
     * @param b : intensidade da cor azul (entre 0 e 1).
     * @param a : intensidade da opacidade (entre 0 e 1).
     */
    PutBox(int x0,int x1,int y0,int y1,int z0,int z1,float r,float g,float b,float a);
    /**
     * @brief draw eh um metodo da classe PutBox que faz com que uma caixa de voxels seja colocada em um objeto Sculptor.
     * @param t : objeto do tipo Sculptor onde a caixa sera colocada.
     */
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
