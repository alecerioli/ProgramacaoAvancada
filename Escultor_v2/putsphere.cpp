#include "putsphere.h"
#include <iostream>
#include <cmath>

using namespace std;


PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

void PutSphere::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i=xcenter-radius; i<=xcenter+radius; i++){
        for (int j=ycenter-radius; j<=ycenter+radius; j++) {
            for (int k=zcenter-radius; k<=zcenter+radius; k++){
                double dist = pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2);
                if(dist<=pow(radius,2)){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}

