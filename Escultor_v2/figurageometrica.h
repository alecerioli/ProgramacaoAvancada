#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/**
 * @brief A classe FiguraGeometrica
 * eh uma classe abstrata que representa objetos geometricos genericos.
 */
class FiguraGeometrica{
protected:
    /**
     * @brief r : intensidade da cor vermelha (entre 0 e 1).
     */
    float r;
    /**
     * @brief g : intensidade da cor verde (entre 0 e 1).
     */
    float g;
    /**
     * @brief b : intensidade da cor azul (entre 0 e 1).
     */
    float b;
    /**
     * @brief a : intensidade da opacidade (entre 0 e 1).
     */
    float a;
public:
    /**
     * @brief FiguraGeometrica eh o construtor da classe FiguraGeometrica.
     */
    FiguraGeometrica();
    /**
     * @brief draw eh o metodo abstrato que desenha algum objeto derivado em um objeto do tipo Sculptor.
     * @param t : objeto do tipo Sculptor no qual sera realizado o desenho.
     */
    virtual void draw(Sculptor &t)=0;
    /**
     * @brief ~FiguraGeometrica eh o destrutor da classe FiguraGeometrica.
     */
    virtual ~FiguraGeometrica();
};

#endif // FIGURAGEOMETRICA_H
