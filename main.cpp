#include <iostream>
#include "color.h"

using namespace std;

int main()
{
    color c1(1,0,0),c2(1,1,0),c3;
    c3=c1.combina(c2);
    c3.print();
    cout<<c1.compara(c2)<<endl;
    cout<<c2.compara(c2)<<endl;
    return 0;
}
