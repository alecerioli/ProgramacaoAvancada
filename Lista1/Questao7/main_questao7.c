#include <stdio.h>

int main()
{
    int *pulo;
    *(pulo + 2);
    //represena o VALOR do terceiro elemento do vetor
    *(pulo + 4);
    //nao representa o terceiro elemento do vetor
    pulo + 4;
    //nao representa o terceiro elemento do vetor
    pulo + 2;
    //representa o ENDERECO do terceiro elemento, e nao o VALOR
    return 0;
}
