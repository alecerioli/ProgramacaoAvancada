#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutEllipsoid
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Remove uma elipsoide com dimensoes e coordenadas definidas.
 */
class CutEllipsoid:public FiguraGeometrica{
    /**
     * @brief xcenter : coordenada x do centro da elipsoide.
     */
    int xcenter;
    /**
     * @brief ycenter : coordenada y do centro da elipsoide.
     */
    int ycenter;
    /**
     * @brief zcenter : coordenada z do centro da elipsoide.
     */
    int zcenter;
    /**
     * @brief rx : raio referente ao eixo x.
     */
    int rx;
    /**
     * @brief ry : raio referente ao eixo y.
     */
    int ry;
    /**
     * @brief rz : raio referente ao eixo z.
     */
    int rz;
public:
    /**
     * @brief CutEllipsoid eh o construtor da classe CutEllipsoid.
     * @param xcenter : coordenada x do centro da elipsoide.
     * @param ycenter : coordenada y do centro da elipsoide.
     * @param zcenter : coordenada z do centro da elipsoide.
     * @param rx : raio referente ao eixo x.
     * @param ry : raio referente ao eixo y.
     * @param rz : raio referente ao eixo z.
     */
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief draw eh um metodo da classe CutEllipsoid que faz com que uma elipsoide seja removida de um objeto Sculptor.
     * @param t : objeto do tipo Sculptor onde a elipsoide sera removida.
     */
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
