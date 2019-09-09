#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ofstream fout;
    ifstream fin;
    fin.open("C:/Users/MatrizD42018/Documents/saida.txt");
    if(!fin.is_open()){
        exit(0);
    }
    // abrir o arquivo
    fout.open("C:/Users/MatrizD42018/Documents/saida2.txt");
    // verificar se estah aberto
    if(!fout.is_open()){
        exit(0);
    }
    string s,comando;
    while (1){
        getline(fin,s);
        if(fin.good()){
            stringstream ss(s);
            ss >> comando;
            cout <<comando <<endl;
            if(comando.compare("dim")== 0){
                int nx,ny,nz;
                ss>>nx>>ny>>nz;
                cout<<nx<<"x" <<ny<<"x"<<nz<<endl;
            }
            else if (comando.compare("putvoxel")==0){
                int pos[3];
                float color[4];
                ss>>pos[0]>>pos[1]>>pos[2]>>color[0]>>color[1]>>color[2]>>color[3];
                cout<<pos[0]<<","<<pos[1]<<","<<pos[2]<<";"<<color[0]<<","<<color[1]<<","<<color[2]<<","<<color[3]<<endl;
            }
        }
        else{
            break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
