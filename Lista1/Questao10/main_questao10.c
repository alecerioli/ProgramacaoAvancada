#include <stdio.h>

int main()
{
    //Supondo que o endereco de x[0] seja 4092 e:
    //--x for declarado como char:
    //  x+1 será 4093, x+2 será 4094 e x+3 será 4095,
    //  isso porque um char ocupa 1 byte.
    //--x for declarado como int:
    //  x+1 será 4094, x+2 será 4096 e x+3 será 4098,
    //  isso porque um int ocupa 2 bytes.
    //--x for declarado como float:
    //  x+1 será 4096, x+2 será 5000 e x+3 será 5004,
    //  isso porque um float ocupa 4 bytes.
    //--x for declarado como double:
    //  x+1 será 5000, x+2 será 5008 e x+3 será 5016,
    //  isso porque um double ocupa 8 bytes.
    return 0;
}
