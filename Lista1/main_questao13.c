#include <stdio.h>

void compara(int *e1, int *e2) {
   printf("%d\n",(*e1 - *e2));
}
//Funcao que imprime numero positivo se
//e1>e2, retorna zero se e1=e2 e retorna
//numero negativo se e1<e2

int main()
{
    //Ponteiros para funcoes servem principalmente para definir
    //uma função que será executada, sem a
    //necessidade de escrever o nome da função.
    //A seguir, um exemplo do uso desse recurso:
    void (*ponteiro)();
    //Ponteiro para funcao
    int a=1;
    int b=4;
    ponteiro = compara;
    //Atribuindo a funcao para o ponteiro
    (*ponteiro)(&a, &b);
    //Chama a funcao atraves do ponteiro
    return 0;
}
