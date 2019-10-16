#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutSphere
 * eh uma classe derivada da classe abstrata FiguraGeometrica.
 * Remove uma esfera com raio e coordenadas definidas.
 */
class CutSphere :public FiguraGeometrica{
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
     * @brief CutSphere eh o construtor da classe CutSphere.
     * @param xcenter : coordenada x do centro da esfera.
     * @param ycenter : coordenada y do centro da esfera.
     * @param zcenter : coordenada z do centro da esfera.
     * @param radius : raio da esfera.
     */
    CutSphere(int xcenter, int ycenter,int zcenter, int radius);
    /**
     * @brief draw eh um metodo da classe CutSphere que faz com que uma esfera seja removida de um objeto Sculptor.
     * @param t: objeto do tipo Sculptor onde a esfera sera removida.
     */
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
