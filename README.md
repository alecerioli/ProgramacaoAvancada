# ProgramacaoAvancada
Trabalhos da materia Programação Avançada

**Sobre o uso do Escultor_v2** :  

-Crie um projeto;  
-Crie todas as classes (*headers* e *source*) copiando os codigos presentes na pasta do arquivo;  
     -OBS: O arquivo *Voxel* é apenas *header*:  
     
     `#ifndef VOXEL_H
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
      #endif // VOXEL_H`  
      



