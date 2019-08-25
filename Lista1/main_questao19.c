#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiplica(int **A,int **B,int **C,int nlA,int ncA,int ncB){
    int i,j,k,soma;
    for(i=0;i<nlA;i++){
        for(j=0;j<ncB;j++){
            soma=0;
            for(k=0;k<ncA;k++){
                soma=soma+A[i][k]*B[k][j];
            }
            C[i][j]=soma;
        }
    }
}


int main()
{
    int i,j;
    int nlA=3;
    int ncA=2;
    int nlB=2;
    int ncB=3;
    int **A,**B,**C;
    A = (int**) malloc(nlA*sizeof(int*));
    B = (int**) malloc(nlB*sizeof(int*));
    C = (int**) malloc(nlA*sizeof(int*));
    for(i=0; i<nlA; i++){
        A[i] = malloc(ncA*sizeof (int));
    }
    for(i=0; i<nlB; i++){
        B[i] = malloc(ncB*sizeof (int));
    }
    for(i=0; i<nlA; i++){
        C[i] = malloc(ncB*sizeof (int));
    }
    for(i=0;i<nlA;i++){
        for(j=0;j<ncA;j++){
            A[i][j]=3*i+2*j;
        }
    }
    for(i=0;i<nlB;i++){
        for(j=0;j<ncB;j++){
            B[i][j]=i+5*j;
        }
    }
    for(i=0;i<nlA;i++){
        for(j=0;j<ncA;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<nlB;i++){
        for(j=0;j<ncB;j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    multiplica(A,B,C,nlA,ncA,ncB);
    printf("\n");
    for(i=0;i<nlA;i++){
        for(j=0;j<ncB;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<nlA; i++){
        free (A[i]);
    }
    free (A);
    for(int i=0; i<nlB; i++){
        free (B[i]);
    }
    free (B);
    for(int i=0; i<nlA; i++){
        free (C[i]);
    }
    free (C);
    return 0;
}
