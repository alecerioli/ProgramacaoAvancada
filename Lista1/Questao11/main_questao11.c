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
    //Como 'px' é do tipo char, os enderecos andam de 1 byte
    printf("\n%X %X %X %X ",py,py+1,py+2,py+3);
    //Como 'py' é do tipo int, os enderecos andam de 2 bytes
    printf("\n%X %X %X %X ",pz,pz+1,pz+2,pz+3);
    //Como 'pz' é do tipo float, os enderecos andam de 4 bytes
    printf("\n%X %X %X %X ",pw,pw+1,pw+2,pw+3);
    //Como 'pw' é do tipo double, os enderecos andam de 8 bytes
    return 0;
}
