#include "cutsphere.h"
#include <cmath>


CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
}

void CutSphere::draw(Sculptor &t){
    for(int i=xcenter-radius; i<=xcenter+radius; i++){
        for (int j=ycenter-radius; j<=ycenter+radius; j++) {
            for (int k=zcenter-radius; k<=zcenter+radius; k++){
                double dist = pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2);
                if(dist<=pow(radius,2)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}

