#include <stdio.h>

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
    //A funcao 'meuordena' chama a funcao 'compara'
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
    int i;
    float *vetor;
    int (*ptrCompara)();
    ptrCompara=compara;
    vetor=malloc(5*sizeof(float));
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
    meuordena(vetor,5,ptrCompara);
    //Chamada da funcao 'meuordena' com os seguintes
    //argumentos, respectivamente: endereco do primeiro
    //elemento do vetor a ser ordenado, tamanho do vetor,
    //ponteiro para a funcao 'compara'.
    for(i=0;i<5;i++){
        printf("%f ",vetor[i]);
    }
    //Impressao do vetor ordenado.
    free(vetor);
    //Liberacao da memoria utilizada.
    return 0;
}
