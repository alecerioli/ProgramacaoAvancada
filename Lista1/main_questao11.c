#include <stdio.h>

int main()
{
    char x[4];
    int y[4];
    float z[4];
    double w[4];
    char *px;
    int *py;
    float *pz;
    double *pw;
    printf("%X %X %X %X ",px,px+1,px+2,px+3);
    //Os enderecos andam de 1 byte
    printf("\n%X %X %X %X ",py,py+1,py+2,py+3);
    //Os enderecos andam de 4 bytes pois
    //o tipo 'int' pode ser tanto 2 quanto 4
    //dependendo da maquina
    printf("\n%X %X %X %X ",pz,pz+1,pz+2,pz+3);
    //Os enderecos andam de 4 bytes
    printf("\n%X %X %X %X ",pw,pw+1,pw+2,pw+3);
    //Os enderecos andam de 8 bytes
    return 0;
}
