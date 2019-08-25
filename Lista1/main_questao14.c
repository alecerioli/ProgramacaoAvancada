#include <stdio.h>
#define TAM 5


void ordena(float *vetor, int n){
    int j,k;
    float aux;
    for(k=0;k<n-1;k++){
        float menor=vetor[k];
        for(j=k+1;j<n;j++){
            if(vetor[j]<menor){
                aux=menor;
                menor=vetor[j];
                vetor[j]=aux;
            }
        }
        vetor[k]=menor;
    }
}

int main()
{
    int i;
    float w;
    float *vetor;
    vetor=malloc(5*sizeof(w));
    vetor[0]=112.1;
    vetor[1]=2.3;
    vetor[2]=32.3;
    vetor[3]=11.9;
    vetor[4]=5.2;
    for(i=0;i<5;i++){
        printf("%f ",vetor[i]);
    }
    printf("\n");
    ordena(vetor,5);
    for(i=0;i<5;i++){
        printf("%f ",vetor[i]);
    }
    free(vetor);
}
