#ifndef VOXEL_H
#define VOXEL_H

/**
 * @brief A struct Voxel
 * eh uma unidade equivalente aos Pixels que comumente são usados em imagens digitais.
 */
struct Voxel {
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
    float b; // Colors
    /**
     * @brief a : intensidade da opacidade (entre 0 e 1).
     */
    float a; // Transparency
    /**
     * @brief isOn : define se o voxel esta ativo ou nao.
     */
    bool isOn; // Included or not
};

#endif // VOXEL_H
