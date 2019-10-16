#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    this->nx=_nx;
    this->ny=_ny;
    this->nz=_nz;
    if(nx<0 || ny<0 || nz<0){
        nx=0;
        ny=0;
        nz=0;
    }
    v= new Voxel**[nz];
    v[0]= new Voxel*[nz*nx];
    for (int i=1;i<nz;i++){
        v[i]= v[i-1]+ nx;
    }
    v[0][0]= new Voxel[nz*ny*nx];
    int n = 0;
    for (int i=0; i<nz;i++){
        for(int j=0; j<nx;j++){
            v[i][j] = v[0][0] + n*ny;
            n++;
        }
    }
    for(int i=0;i<nz*nx*ny;i++){
        v[0][0][i].isOn=false;
    }
    cout<<"construtor desenho\n";

}

Sculptor::~Sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
    cout<<"destrutor desenho\n";
}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    if(x<nx && x>0){
        if(y<ny && y>0){
            if(z<nz && z>0){
                v[x][y][z].isOn=true;
                v[x][y][z].r=r;
                v[x][y][z].g=g;
                v[x][y][z].b=b;
                v[x][y][z].a=a;
            }
        }
    }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    if(x<nx && x>0){
        if(y<ny && y>0){
            if(z<nz && z>0){
                v[x][y][z].isOn=false;
            }
        }
    }
}

void Sculptor::writeOFF(const char *filename)
{
    ofstream fout;
    int vertices=0;
    int faces=0;
    fout.open(filename);
    if(fout.is_open()){
        cout << "Arquivo OFF aberto com sucesso" << endl;
    }
    else{
        cout << "Nao foi possivel abrir o arquivo OFF"<< endl;
        exit(0);
    }
    fout<<"OFF"<<endl;
    for (int i=0;i<nz;i++) {
        for (int j=0;j<nx;j++) {
            for(int k=0;k<ny;k++){
                if(v[i][j][k].isOn == true){
                    vertices=vertices+8;
                    faces=faces+6;
                }
            }
        }
    }
    fout<<vertices<<" "<<faces<<" 0"<<endl;
    for (int i=0;i<nz;i++) {
        for (int j=0;j<nx;j++) {
            for(int k=0;k<ny;k++){
                if(v[i][j][k].isOn == true){
                    fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                    fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }
    }
    int aux=0;
    for (int i=0;i<nz;i++) {
        for (int j=0;j<nx;j++) {
            for(int k=0;k<ny;k++){
                if(v[i][j][k].isOn == true){
                    fout<<"4 "<< aux<< " "<< aux +3<<" "<< aux+2 <<" "<< aux+1;
                    fout<<" "<<setprecision(3)<<v[i][j][k].r <<" "<<setprecision(3)<< v[i][j][k].g<<" "<<setprecision(3)<<v[i][j][k].b<<" "<<setprecision(3)<<v[i][j][k].a<<endl;
                    fout<<"4 "<< aux+4<< " "<< aux +5<<" "<< aux+6 <<" "<< aux+7;
                    fout<<" "<<setprecision(3)<<v[i][j][k].r <<" "<<setprecision(3)<< v[i][j][k].g<<" "<<setprecision(3)<<v[i][j][k].b<<" "<<setprecision(3)<<v[i][j][k].a<<endl;
                    fout<<"4 "<< aux<< " "<< aux +1<<" "<< aux+5 <<" "<< aux+4;
                    fout<<" "<<setprecision(3)<<v[i][j][k].r <<" "<<setprecision(3)<< v[i][j][k].g<<" "<<setprecision(3)<<v[i][j][k].b<<" "<<setprecision(3)<<v[i][j][k].a<<endl;
                    fout<<"4 "<< aux<< " "<< aux +4<<" "<< aux+7 <<" "<< aux+3;
                    fout<<" "<<setprecision(3)<<v[i][j][k].r <<" "<<setprecision(3)<< v[i][j][k].g<<" "<<setprecision(3)<<v[i][j][k].b<<" "<<setprecision(3)<<v[i][j][k].a<<endl;
                    fout<<"4 "<< aux+3<< " "<< aux +7<<" "<< aux+6 <<" "<< aux+2;
                    fout<<" "<<setprecision(3)<<v[i][j][k].r <<" "<<setprecision(3)<< v[i][j][k].g<<" "<<setprecision(3)<<v[i][j][k].b<<" "<<setprecision(3)<<v[i][j][k].a<<endl;
                    fout<<"4 "<< aux+1<< " "<< aux +2<<" "<< aux+6 <<" "<< aux+5;
                    fout<<" "<<setprecision(3)<<v[i][j][k].r <<" "<<setprecision(3)<< v[i][j][k].g<<" "<<setprecision(3)<<v[i][j][k].b<<" "<<setprecision(3)<<v[i][j][k].a<<endl;
                    aux+=8;
                }
            }
        }
    }
    fout.close();
}
