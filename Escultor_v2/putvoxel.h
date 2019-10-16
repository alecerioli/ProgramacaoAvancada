#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe PutVoxel
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Coloca um voxel com coordenadas e cor definidas.
 */
class PutVoxel : public FiguraGeometrica{
    /**
     * @brief x : coordenada x.
     */
    int x;
    /**
     * @brief y : coordenada y.
     */
    int y;
    /**
     * @brief z : coordenada z.
     */
    int z;
public:
    /**
     * @brief PutVoxel eh o construtor da classe PutVoxel.
     * @param x : coordenada x.
     * @param y : coordenada y.
     * @param z : coordenada z.
     * @param r : intensidade da cor vermelha (entre 0 e 1).
     * @param g : intensidade da cor verde (entre 0 e 1).
     * @param b : intensidade da cor azul (entre 0 e 1).
     * @param a : intensidade da opacidade (entre 0 e 1).
     */
    PutVoxel(int x,int y,int z,float r,float g,float b,float a);
    /**
     * @brief draw eh um metodo da classe PutVoxel que faz com que um voxel seja colocado em um objeto Sculptor.
     * @param t : objeto do tipo Sculptor onde o voxel sera colocado.
     */
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
