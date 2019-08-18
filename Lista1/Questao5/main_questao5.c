#include <stdio.h>

int main()
{
    int    valor;
    int   *p1;
    float  temp;
    float *p2;
    char   aux;
    char  *nome = "Ponteiros";
    char  *p3;
    int    idade;
    int    vetor[3];
    int   *p4;
    int   *p5;

    /* (a) */
    valor = 10;
    p1 = &valor;
    *p1 = 20;
    //Será impresso o 20, uma vez que o conteudo de
    //'valor' está sendo substituido por 20
    printf("%d \n", valor);

    /* (b) */
    temp = 26.5;
    p2 = &temp;
    *p2 = 29.0;
    //Será impresso o  29.0, uma vez que o conteudo de
    //'temp' está sendo substituido por 29.0
    printf("%.1f \n", temp);

    /* (c) */
    p3 = &nome[0];
    aux = *p3;
    //Será impresso o 'P', uma vez que 'aux' representa o conteudo
    //de 'p3' que de consequencia representa o endereco do 'P'
    printf("%c \n", aux);

    /* (d) */
    p3 = &nome[4];
    aux = *p3;
    //Será impresso o 'e', uma vez que 'aux' representa o conteudo
    //de 'p3' que de consequencia representa o endereco do 'e'
    printf("%c \n", aux);

    /* (e) */
    p3 = nome;
    //Será impresso o 'P', uma vez que mandando imprimir o nome de
    //um ponteiro que representa um vetor resultará na impressao do
    //primeiro elemento do vetor
    printf("%c \n", *p3);

    /* (f) */
    p3 = p3 + 4;
    //Será impresso o 'e', uma vez que andando 4 elementos depois do 'P'
    //temos o 'e'
    printf("%c \n", *p3);

    /* (g) */
    p3--;
    //Será impresso o 't', uma vez que andando 1 elemento para tras do 'e'
    //temos o 't'
    printf("%c \n", *p3);

    /* (h) */
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;
    idade = *p4;
    //Será impresso 31, pelo mesmo motivo da letra e)
    printf("%d \n", idade);

    /* (i) */
    p5 = p4 + 1;
    idade = *p5;
    //Será impresso o 45, pelo mesmo motivo da letra f)
    printf("%d \n", idade);

    /* (j) */
    p4 = p5 + 1;
    idade = *p4;
    //Será impresso o 27, pelo mesmo motivo da letra i)
    printf("%d \n", idade);

    /* (l) */
    p4 = p4 - 2;
    idade = *p4;
    //Será impresso o 31, pelo mesmo motivo da letra g)
    printf("%d \n", idade);

    /* (m) */
    p5 = &vetor[2] - 1;
    //Será impresso o 45, uma vez que andando um "endereco" para
    //tras do elemento [2] temos o elemento [1]
    printf("%d \n", *p5);

    /* (n) */
    p5++;
    //Será impresso o 27, uma vez que andando um "endereco" para
    //frente do elemento [1] voltamos para o elemento [2]
    printf("%d \n", *p5);
    return(0);
}
