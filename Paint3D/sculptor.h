#ifndef VOXEL_H
#define VOXEL_H
/**
 * @brief A struct Voxel
 * seria algo equivalente aos Pixels usados em imagens digitais,
 * sendo possivel nos Voxels armazenar cor e transparência.
 * @param r: intensidade da cor vermelha.
 * @param g: intensidade da cor verde.
 * @param b: intensidade da cor azul.
 * @param a: intensidade da opacidade.
 * @param isOn: binario que define se o Voxel está ativo ou nao.
 */
struct Voxel {
    float r;
    float g;
    float b;
    float a;
    bool isOn;
};
#endif // VOXEL_H



#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <cstring>
#include <iostream>

/**
 * @brief A classe Sculptor
 * cria e manipula uma matriz 3D de Voxels.
 */
class Sculptor {
public:
    /**
     * @brief v: ponteiro para uma matriz 3D de Voxels alocada dinamicamente.
     */
    Voxel ***v;
    /**
     * @brief nx: dimensao X.
     */
    int nx;
    /**
     * @brief ny: dimensao Y.
     */
    int ny;
    /**
     * @brief nz: dimensao Z.
     */
    int nz;
    /**
     * @brief r: intensidade da cor vermelha.
     */
    float r;
    /**
     * @brief g: intensidade da cor verde.
     */
    float g;
    /**
     * @brief b: intensidade da cor azul.
     */
    float b;
    /**
     * @brief a: intensidade da opacidade.
     */
    float a;
    /**
     * @brief Sculptor eh o construtor da classe Sculptor.
     * @param _nx: futura dimensao X.
     * @param _ny: futura dimensao Y.
     * @param _nz: futura dimensao Z.
     */
    Sculptor(int _nx, int _ny, int _nz);
    /**
     * @brief ~Sculptor eh o destrutor da classe Sculptor.
     */
    ~Sculptor();
    /**
     * @brief setColor eh um metodo que define a cor do desenho.
     * @param r: futura intensidade da cor vermelha.
     * @param g: futura intensidade da cor verde.
     * @param b: futura intensidade da cor azul.
     * @param alpha: futura intensidade da opacidade.
     */
    void setColor(float r, float g, float b, float alpha);
    /**
     * @brief putVoxel eh um metodo que ativa um Voxel na posicao especificada.
     * @param x: posicao X.
     * @param y: posicao Y.
     * @param z: posicao Z.
     */
    void putVoxel(int x, int y, int z);
    /**
     * @brief cutVoxel eh um metodo que desativa um Voxel na posicao especificada.
     * @param x: posicao X.
     * @param y: posicao Y.
     * @param z: posicao Z.
     */
    void cutVoxel(int x, int y, int z);
    /**
     * @brief putBox eh um metodo que ativa uma caixa de Voxels na posicao especificada.
     * @param x0: posicao X inicial.
     * @param x1: posicao X final.
     * @param y0: posicao Y inicial.
     * @param y1: posicao Y final.
     * @param z0: posicao Z inicial.
     * @param z1: posicao Z final.
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief cutBox eh um metodo que desativa uma caixa de Voxels na posicao especificada.
     * @param x0: posicao X inicial.
     * @param x1: posicao X final.
     * @param y0: posicao Y inicial.
     * @param y1: posicao Y final.
     * @param z0: posicao Z inicial.
     * @param z1: posicao Z final.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief putSphere eh um metodo que ativa uma esfera de Voxels na posicao especificada.
     * @param xcenter: posicao X do centro.
     * @param ycenter: posicao Y do centro.
     * @param zcenter: posicao Z do centro.
     * @param radius: raio da esfera.
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief cutSphere eh um metodo que desativa uma esfera de Voxels na posicao especificada.
     * @param xcenter: posicao X do centro.
     * @param ycenter: posicao Y do centro.
     * @param zcenter: posicao Z do centro.
     * @param radius: raio da esfera.
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief putEllipsoid eh um metodo que ativa uma elipsoide de Voxels na posicao especificada.
     * @param xcenter: posicao X do centro.
     * @param ycenter: posicao Y do centro.
     * @param zcenter: posicao Z do centro.
     * @param rx: raio X da elipsoide.
     * @param ry: raio Y da elipsoide.
     * @param rz: raio Z da elipsoide.
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief cutEllipsoid eh um metodo que desativa uma elipsoide de Voxels na posicao especificada.
     * @param xcenter: posicao X do centro.
     * @param ycenter: posicao Y do centro.
     * @param zcenter: posicao Z do centro.
     * @param rx: raio X da elipsoide.
     * @param ry: raio Y da elipsoide.
     * @param rz: raio Z da elipsoide.
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief writeOFF eh um metodo que salva a matriz 3D no formato OFF.
     * @param filename: endereco onde será salvo o arquivo.
     */
    void writeOFF(std::string filename);
};
#endif // SCULPTOR_H
