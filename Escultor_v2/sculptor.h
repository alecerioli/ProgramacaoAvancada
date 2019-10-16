#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
#include <string>
#include <iostream>

/**
 * @brief A classe Sculptor
 * eh uma classe que permite criar e modificar uma matriz 3D de Voxel.
 */
class Sculptor{
protected:
    /**
     * @brief v : matriz 3D de Voxels alocada dinamicamente.
     */
    Voxel ***v; // 3D matrix
    /**
     * @brief nx : dimensao de x.
     */
    int nx;
    /**
     * @brief ny : dimensao de y.
     */
    int ny;
    /**
     * @brief nz : dimensao de z.
     */
    int nz; // Dimensions
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
    float a; // Current drawing color
public:
    /**
     * @brief Sculptor eh o construtor da classe Sculptor.
     * @param _nx : dimensao de x.
     * @param _ny : dimensao de y.
     * @param _nz : dimensao de z.
     */
    Sculptor(int _nx, int _ny, int _nz);
    /**
     * @brief ~Sculptor eh o destrutor da classe Sculptor.
     */
    ~Sculptor();
    /**
     * @brief setColor eh um metodo da classe Sculptor que define a cor atual.
     * @param r : intensidade da cor vermelha (entre 0 e 1).
     * @param g : intensidade da cor verde (entre 0 e 1).
     * @param b : intensidade da cor azul (entre 0 e 1).
     * @param alpha : intensidade da opacidade (entre 0 e 1).
     */
    void setColor(float r, float g, float b, float alpha);
    /**
     * @brief putVoxel eh um metodo da classe Sculptor que ativa um voxel com coordenadas definidas e na cor atual.
     * @param x : coordenada x.
     * @param y : coordenada y.
     * @param z : coordenada z.
     */
    void putVoxel(int x, int y, int z);
    /**
     * @brief cutVoxel eh um metodo da classe Sculptor que desativa um voxel com coordenadas definidas.
     * @param x : coordenada x.
     * @param y : coordenada y.
     * @param z : coordenada z.
     */
    void cutVoxel(int x, int y, int z);
    /**
     * @brief writeOFF eh um metodo da classe Sculptor que grava a matriz 3D de Voxel em um arquivo.off.
     * @param filename : caminho do arquivo.off.
     */
    void writeOFF(const char *filename);
};

#endif // SCULPTOR_H
