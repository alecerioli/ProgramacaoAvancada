#include <stdio.h>

int main()
{
    int i,j,*p,*q;
    //p = i;
    //atribuicao ilegal-- 'p' é ponteiro e essa atribuicao tem
    //que ser feita utilizando &
    q = &j;
    //atribuicao legal
    p = &*&i;
    //atribuicao legal
    //i = (*&)j;
    //atribuicao ilegal-- para ser legal, ou nao coloca-se parenteses
    //ou coloca-se o parentese na forma: *(&j)
    i = *&j;
    //atribuicao legal
    i = *&*&j;
    //atribuicao legal
    q = *p;
    // atribuicao ilegal--'p' e 'q' sao ambos ponteiros,
    //portanto nao usa-se o *
    i = (*p)++ + *q;
    //atribuicao legal
    return 0;
}
