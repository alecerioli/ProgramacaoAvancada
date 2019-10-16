#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutVoxel
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Remove um voxel com coordenadas definidas.
 */
class CutVoxel: public FiguraGeometrica{
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
     * @brief CutVoxel eh o construtor da classe CutVoxel.
     * @param x : coordenada x.
     * @param y : coordenada y.
     * @param z : coordenada z.
     */
    CutVoxel(int x,int y, int z);
    /**
     * @brief draw eh um metodo da classe CutVoxel que faz com que um voxel seja removido de um objeto Sculptor.
     * @param t : objeto do tipo Sculptor onde o voxel sera removido.
     */
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
