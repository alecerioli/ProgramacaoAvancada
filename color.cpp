#include "color.h"
#include <iostream>

using namespace std;

color::color(float mr, float mg, float mb)
{
    r=mr;
    g=mg;
    b=mb;
}

color::~color()
{

}

void color::print()
{
    cout<<"["<<r<<","<<g<<","<<b<<"]"<<endl;
}

color color::combina(color c2)
{
    color ret;
    ret.r= (r + c2.r)/2;
    ret.g=(g +c2.g)/2;
    ret.b=(b +c2.b)/2;
    return ret;
}

bool color::compara(color c1)
{
    if(r ==c1.r && g==c1.g && b==c1.b){
        return true;
    }
    else{
        return false;
    }
}
