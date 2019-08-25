#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void meuordena(float *base,int tam,int (*compara)(const void*,const void*)){
    int j,k;
    float aux;
    for(j=0;j<tam-2;j++){
        for(k=0;k<tam-j-1;k++)
        if(compara(base+k,base+k+1)==1){
           aux=*(base+k);
           *(base+k)=*(base+k+1);
           *(base+k+1)=aux;
        }
    }
}

int main()
{
    clock_t start,end;
    float *vetor;
    int (*ptrCompara)();
    ptrCompara=compara;
    vetor=malloc(10*sizeof(float));
    vetor[0]=112.1;
    vetor[1]=2.3;
    vetor[2]=32.3;
    vetor[3]=11.9;
    vetor[4]=5.2;
    vetor[5]=1267.1;
    vetor[6]=26.3;
    vetor[7]=1.1;
    vetor[8]=65.9;
    vetor[9]=3222.8;
    //Atribuicao dos elementos do vetor liberando
    //memoria atravez da funcao 'malloc'.
    float *vetor2;
    int (*ptrCompara2)();
    ptrCompara2=compara;
    vetor2=malloc(10*sizeof(float));
    vetor2[0]=112.1;
    vetor2[1]=2.3;
    vetor2[2]=32.3;
    vetor2[3]=11.9;
    vetor2[4]=5.2;
    vetor2[5]=1267.1;
    vetor2[6]=26.3;
    vetor2[7]=1.1;
    vetor2[8]=65.9;
    vetor2[9]=3222.8;
    //Atribuicao dos elementos do vetor2 liberando
    //memoria atravez da funcao 'malloc'.
    start=clock();
    qsort(vetor,10,sizeof(float),ptrCompara);
    end=clock();
    //Medicao do tempo para a funcao 'qsort'.
    double Tempo =((double)(end-start))/CLOCKS_PER_SEC;
    printf("Tempo gasto em 'qsort': %.8fs\n", Tempo);
    start=clock();
    meuordena(vetor2,10,ptrCompara2);
    end=clock();
    //Medicao do tempo para a funcao 'meuordena'.
    double Tempo2 =((double)(end-start))/CLOCKS_PER_SEC;
    printf("Tempo gasto em 'meuordena': %.8fs\n", Tempo2);
    free(vetor);
    free(vetor2);
    //Liberacao da memoria utilizada.
    return 0;
}
