#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe PutEllipsoid
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Coloca uma elipsoide com dimensoes, coordenadas e cor definidas.
 */
class PutEllipsoid : public FiguraGeometrica{
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
     * @brief PutEllipsoid eh o construtor da classe PutEllipsoid.
     * @param xcenter : coordenada x do centro da elipsoide.
     * @param ycenter : coordenada y do centro da elipsoide.
     * @param zcenter : coordenada z do centro da elipsoide.
     * @param rx : raio referente ao eixo x.
     * @param ry : raio referente ao eixo y.
     * @param rz : raio referente ao eixo z.
     * @param r : intensidade da cor vermelha (entre 0 e 1).
     * @param g : intensidade da cor verde (entre 0 e 1).
     * @param b : intensidade da cor azul (entre 0 e 1).
     * @param a : intensidade da opacidade (entre 0 e 1).
     */
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz,float r,float g,float b,float a);
    /**
     * @brief draw eh um metodo da classe PutEllipsoid que faz com que uma elipsoide seja colocada em um objeto Sculptor.
     * @param t : objeto do tipo Sculptor onde a elipsoide sera colocada.
     */
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
