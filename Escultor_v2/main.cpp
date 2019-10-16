#include <iostream>
#include "figurageometrica.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "putvoxel.h"
#include "putsphere.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "sculptor.h"
#include <vector>
#include <string>
#include "interpreter.h"

using namespace std;


int main(){
    Interpreter tt;
    Sculptor t=tt.Read("C:/Users/User/Documents/entrada1.txt");
    t.writeOFF("C:/Users/User/Documents/saida1.off");
    return 0;
}
