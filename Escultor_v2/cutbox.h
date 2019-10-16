#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutBox
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Remove uma caixa de voxel com coordenadas definidas.
 */
class CutBox:public FiguraGeometrica{
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
     * @brief z0 : coordenada z inicial.
     */
    int z0;
    /**
     * @brief z1 : coordenada z final.
     */
    int z1;
public:
    /**
     * @brief CutBox eh o construtor da classe.
     * @param x0 : coordenada x inicial.
     * @param x1 : coordenada x final.
     * @param y0 : coordenada y inicial.
     * @param y1 : coordenada y final.
     * @param z0 : coordenada z inicial.
     * @param z1 : coordenada z final.
     */
    CutBox(int x0,int x1,int y0,int y1,int z0,int z1);
    /**
     * @brief draw eh um metodo da classe CutBox que faz com que uma caixa de voxel seja removida de um objeto Sculptor.
     * @param t : objeto do tipo Sculptor onde a caixa sera removida.
     */
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
