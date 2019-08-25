#include <stdio.h>
#include <stdlib.h>

int compara (const void *a, const void *b){
    //Cria a funcao 'compara'
    int x;
    if (*(int*)a < *(int*)b){
        x=-1;
    }
    if (*(int*)a > *(int*)b){
        x=1;
    }
    if (*(int*)a == *(int*)b){
        x=0;
    }
    //A funcao 'qsort' chama a funcao 'compara'
    //varias vezes, os retornos da funcao (-1,0 ou 1)
    //vao dizer se deve ser feita a troca ou nao.
    return x;
}

int main()
{
    int i;
    float w;
    float *vetor;
    int (*ptrCompara)();
    ptrCompara=compara;
    vetor=malloc(5*sizeof(w));
    vetor[0]=112.1;
    vetor[1]=2.3;
    vetor[2]=32.3;
    vetor[3]=11.9;
    vetor[4]=5.2;
    //Atribuicao dos elementos do vetor liberando
    //memoria atravez da funcao 'malloc'.
    for(i=0;i<5;i++){
        printf("%f ",vetor[i]);
    }
    //Impressao do vetor NAO ordenado.
    printf("\n");
    qsort(vetor,5,sizeof(float),ptrCompara);
    //Chamada da funcao 'qsort' com os seguintes
    //argumentos, respectivamente: endereco do primeiro
    //elemento do vetor a ser ordenado, tamanho do vetor,
    //tamanho em bytes de cada elemento, ponteiro para a
    //funcao 'compara'.
    for(i=0;i<5;i++){
        printf("%f ",vetor[i]);
    }
    //Impressao do vetor ordenado.
    free(vetor);
    //Liberacao da memoria utilizada.
}
