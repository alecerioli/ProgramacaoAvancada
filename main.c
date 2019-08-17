#include <stdio.h>

int main()
{
    int vet[] = {4,9,13};
    int i;
    for(i=0;i<3;i++){
      printf("%d ",*(vet+i));
    }
    //Serao impressos todos os valores dos elementos do vetor
    for(i=0;i<3;i++){
      printf("%X ",vet+i);
    }
    //Serao impressos todos os enderecos dos elementos do vetor
    return 0;
}
