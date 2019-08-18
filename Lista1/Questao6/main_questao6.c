#include <stdio.h>

int main()
{
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for(i = 0 ; i <= 4 ; i++){
        //Primeiro imprime o indice
        printf("\ni = %d ",i);
        //Em seguida imprime o respectivo elemento ao indice
        //pela notacao classica de vetor (vet[])
        printf("vet[%d] = %.1f ",i, vet[i]);
        //Em seguida imprime o respectivo elemento ao indice
        //pela notacao de ponteiros
        printf("*(f + %d) = %.1f ",i, *(f+i));
        //Depois será impresso o endereco em hexadecimal do respectivo elemento
        //pela notacao classica de vetor
        printf("&vet[%d] = %X ",i, &vet[i]);
        //Por fim será impresso o endereco em hexadecimal do respectivo elemento
        //pela notacao de ponteiros
        printf("(f + %d) = %X ",i, f+i);
    }
}
