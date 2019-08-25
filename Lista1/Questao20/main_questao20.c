#include "gc.h"
#include<stdio.h>
#include<stdlib.h>

int main (){
    int i,n;
    n = 1000;
    GC_INIT();
    for (i=0; i<n; i++){
            int **ptr = (int **) GC_MALLOC(sizeof(int*));
            int *qtr = (int*) GC_MALLOC_ATOMIC(sizeof(int));
            *ptr = (int*) GC_REALLOC(qtr, 2*sizeof(int));
        //Realocamos o ponteiro '*ptr', para assim o programa
        //"apagar" automaticamente o ponteiro '*qtr' que nao será
        //mais utilizado
    }
    //Usando as funcoes da biblioteca libGC torna-se desnecessario
    //o uso da funcão free, mesmo alocando e realocando um numero MUITO
    //grande de memoria (1000 alocacoes e realocacoes).
    return 0;
}
