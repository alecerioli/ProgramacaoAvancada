#include "gc.h"
#include<stdio.h>
#include<stdlib.h>

int main (){
    int i,n;
    n = 1000;
    for (i=0; i<n; i++){
        int *q = (int*)malloc(sizeof(int));
    }
    //Atravez da biblioteca libGC torna-se desnecessario
    //o uso da funcão free, mesmo alocando um numero MUITO
    //grande de memoria (1000 alocacoes);
    return 0;
}
