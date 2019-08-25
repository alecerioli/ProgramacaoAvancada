#include <stdio.h>

int main()
{
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;
    aloha[2] = value;
    //Comando valido: o elemento 2 do vetor
    //'aloha' receberá o valor de 'value'.
    scanf("%f", &aloha);
    //Comando invalido: nao é possivel ler um endereco.
    //aloha = value";
    //Comado invalido: nao é possivel alterar
    //um endereco ('aloha' representa o endereco
    //de 'aloha[0]').
    printf("%f", aloha);
    //Comando valido: o endereco de 'aloha[0]'
    //será impresso como float.
    coisas[4][4] = aloha[3];
    //Comando valido: o elemento [4][4] da matriz
    //'coisas' receberá o valor de 'aloha[3]'.
    //coisas[5] = aloha;
    //Comando invalido: nao é possivel fazer uma
    //atribuicao de uma linha completa de uma matriz.
    //pf = value;
    //Comando invalido: nao é possivel atribuir a um ponteiro
    //(um endereco) um valor comum.
    pf = aloha;
    //Comando valido: como ambos ('pf' e 'aloha')
    //representam ponteiros, essa atribuicao é possivel.
    return 0;
}
