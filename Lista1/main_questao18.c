#include <stdio.h>
#include <stdlib.h>

void somavetor(int *vetor1,int *vetor2, int *vetor3,int n){
    int j;
    for(j=0;j<n;j++){
        *(vetor3+j)=*(vetor1+j)+*(vetor2+j);
    }
}

int main()
{
    int n,i;
    printf("entre com o tamanho: ");
    scanf("%d",&n);
    int *vetor1;
    vetor1=malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("entre com o %d elemento do vetor1: ",i+1);
        scanf("%d",vetor1+i);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",*(vetor1+i));
    }
    printf("\n");
    int *vetor2;
    vetor2=malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("entre com o %d elemento do vetor2: ",i+1);
        scanf("%d",vetor2+i);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",*(vetor2+i));
    }
    int *vetor3;
    vetor3=malloc(4*sizeof(int));
    somavetor(vetor1,vetor2,vetor3,n);
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",*(vetor3+i));
    }
    free(vetor1);
    free(vetor2);
    free(vetor3);
    return 0;
}
