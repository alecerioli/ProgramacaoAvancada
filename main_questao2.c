#include <stdio.h>

int main(){
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;
    //p == &i;
    //O uso de "==" não pode ser usado
    int a=*p - *q;
    printf("%d\n", a);
    //O resultado é -2, sendo o conteudo de 'p' menos o conteudo de 'q'
    int b=**&p;
    printf("%d\n", b);
    //O resultado é 3, uma vez que b reprenta o conteudo do conteudo do endereco de 'p'.
    //O conteudo do endereco de 'p' é o proprio 'p', ficando apenas o conteudo de 'p'
    int c=3 - *p/(*q) + 7;
    printf("%d\n", c);
    //O resultado é 10, uma vez sendo todas as variaveis inteiras e
    // a operacao '3- (3/5) + 7' resulta em 10 (na notacao de inteiro)
    return 0;
}
