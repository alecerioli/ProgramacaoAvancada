#include "gc.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (){
    int i,n;
    clock_t start, end;
    n=1000;
    GC_INIT();
    start = clock();
    for (i=0; i<n; i++){
        int **ptr = (int **)GC_MALLOC(sizeof(int*));
        int *qtr = (int*)GC_MALLOC_ATOMIC(sizeof(int));
        *ptr = (int*)GC_REALLOC(qtr, 2*sizeof(int));
        //Usamos as funcoes da biblioteca libGC para
        //que o programa libere a memoria automaticamente
        //sempre que nao necessitarmos mais do ponteiro em questao
        //(nesse caso toda vez que atualizar o valor de 'i')
    }
    end = clock();
    double tempo = ((double) (end -start))/CLOCKS_PER_SEC;
    printf("Tempo usando a libGC: %.8f\n", tempo);
    start = clock();
    for (i=0; i<n; i++){
        int **ptr = (int **) malloc(sizeof(int*));
        int *qtr = (int*) malloc(sizeof(int));
        *ptr = (int*) realloc(qtr, 2*sizeof(int));
        free(*ptr);
        free(ptr);
        //Nesse caso usamos 'malloc' e 'free' normalmente
    }
    end = clock();
    double tempo2 = ((double)(end -start))/CLOCKS_PER_SEC;
    printf("Tempo usando 'malloc' e 'free': %.8f\n", tempo2);
    return 0;
}
