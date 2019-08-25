#include <stdio.h>

int main()
{
    int mat[4], *p, x;
    p = mat + 1;
    //Expressao valida, uma vez que apenas o nome 'mat' representa o
    //endereco do primeiro elemento do vetor, e adicionando '1'
    //andamos um elemento para frente
    //p = mat++;
    //Expressao invalida, pois nao podemos incrementar ao mesmo tempo
    //que fazemos atribuicao
    //p = ++mat;
    //Expressao invalida, pelo mesmo motivo do item anterior
    x = (*mat)++;
    //Expressao valida, uma vez que 'x' recebe o conteudo de 'mat[0]'
    //e incrementa
    return 0;
}
