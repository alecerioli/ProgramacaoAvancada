#ifndef PUTSHPERE_H
#define PUTSHPERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe PutSphere
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Coloca uma esfera com raio, coordenadas e cor definidas.
 */
class PutSphere : public FiguraGeometrica{
    /**
     * @brief xcenter : coordenada x do centro da esfera.
     */
    int xcenter;
    /**
     * @brief ycenter : coordenada y do centro da esfera.
     */
    int ycenter;
    /**
     * @brief zcenter : coordenada z do centro da esfera.
     */
    int zcenter;
    /**
     * @brief radius : raio da esfera.
     */
    int radius;
public:
    /**
     * @brief PutSphere eh o construtor da classe PutSphere.
     * @param xcenter : coordenada x do centro da esfera.
     * @param ycenter : coordenada y do centro da esfera.
     * @param zcenter : coordenada z do centro da esfera.
     * @param radius : raio da esfera.
     * @param r : intensidade da cor vermelha (entre 0 e 1).
     * @param g : intensidade da cor verde (entre 0 e 1).
     * @param b : intensidade da cor azul (entre 0 e 1).
     * @param a : intensidade da opacidade (entre 0 e 1).
     */
    PutSphere(int xcenter, int ycenter,int zcenter, int radius,float r,float g,float b,float a);
    /**
     * @brief draw eh um metodo da classe PutSphere que faz com que uma esfera seja colocada em um objeto Sculptor.
     * @param t : objeto do tipo Sculptor onde a esfera sera colocada.
     */
    void draw(Sculptor &t);
};

#endif // PUTSHPERE_H
