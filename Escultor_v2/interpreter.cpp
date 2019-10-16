#include <iostream>
#include "sculptor.h"
#include <string>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "figurageometrica.h"
#include "interpreter.h"
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

Interpreter::Interpreter()
{

}

Sculptor Interpreter::Read(const char *filename)
{
    ifstream fin;
    fin.open(filename);
    Sculptor *t;
    vector<FiguraGeometrica*> f;
    string s,comando;
    if(fin.is_open()){
        cout << "Arquivo de entrada aberto com sucesso" << endl;
    }
    else{
        cout << "Nao foi possivel abrir o arquivo de entrada"<< endl;
        exit(0);
    }
    while(fin.good()){
        getline(fin,s);
        stringstream ss(s);
        ss>>comando;
        if (comando.compare("dim")==0){
            int nx,ny,nz;
            ss >> nx >> ny >> nz;
            t=new Sculptor(nx,ny,nz);
        }
        else if (comando.compare("putvoxel")==0) {
            int x,y,z;
            float r,g,b,a;
            ss >> x >> y >> z >> r >> g >> b >> a;
            f.push_back(new PutVoxel(x,y,z,r,g,b,a));
        }
        else if (comando.compare("cutvoxel")==0) {
            int x,y,z;
            ss >> x >> y >> z ;
            f.push_back(new CutVoxel(x,y,z));
        }
        else if (comando.compare("putbox")==0) {
            int x0,x1,y0,y1,z0,z1;
            float r,g,b,a;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            f.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }
        else if (comando.compare("cutbox")==0) {
            int x0,x1,y0,y1,z0,z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            f.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
        }
        else if (comando.compare("putsphere")==0) {
            int xcenter,ycenter,zcenter,radius;
            float r,g,b,a;
            ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            f.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }
        else if (comando.compare("cutsphere")==0) {
            int xcenter,ycenter,zcenter,radius;
            ss >> xcenter >> ycenter >> zcenter >> radius;
            f.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));
        }
        else if (comando.compare("putellipsoid")==0) {
            int xcenter,ycenter,zcenter,rx,ry,rz;
            float r,g,b,a;
            ss >> xcenter >> ycenter >> zcenter >> rx >>ry >>rz >> r >> g >> b >> a;
            f.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }
        else if (comando.compare("cutellipsoid")==0) {
            int xcenter,ycenter,zcenter,rx,ry,rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >>ry >>rz;
            f.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
        }
    }
    for (int i=0; i<f.size(); i++) {
        f[i]->draw(*t);
        delete f[i];
    }
    fin.close();
    return *t;
}
