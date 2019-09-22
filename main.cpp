#include <iostream>
#include "voxel.h"
#include "sculptor.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    Sculptor S(31,31,31);
    S.setColor(1,0,1,1);
    S.putVoxel(30,1,1);
    S.putVoxel(30,2,1);
    S.cutVoxel(30,2,1);
    S.setColor(1,0,0,0);
    S.putBox(0,3,0,4,0,3);
    S.putBox(3,5,4,5,3,6);
    S.cutBox(3,5,4,5,3,6);
    S.putSphere(10,10,10,7);
    S.putSphere(20,20,20,5);
    S.cutSphere(20,20,20,5);
    S.putEllipsoid(23,22,22,2,5,6);
    S.putEllipsoid(17,18,17,2,5,3);
    S.cutEllipsoid(17,18,17,2,5,3);
    S.writeOFF("C:/Users/User/Documents/saida.off.txt");
    return 0;
}
