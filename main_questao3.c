#include <stdio.h>

int main()
{
    int i=5, *p;
    p = &i;
    printf("%x %d %d %d %d\n", p,*p+2,**&p,3**p,**&p+4);
    //Primeiro será impresso o endereco em hexadecimal, depois 7
    //(conteudo de 'p' + 2), em seguida 5 (conteudo do conteudo do
    //endereco de 'p', resultando no conteudo de 'p'), em seguida 15
    //(3 vezes o conteudo de 'p') e por fim será impresso 9
    //(mesma logica do terceiro elemento somando 4).
    return 0;
}
