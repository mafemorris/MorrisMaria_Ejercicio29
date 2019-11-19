#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template <class T>
void escribe(string archivo, T* datos1, int n_dat){
  ofstream outfile;
  //abre el archivo.
  outfile.open(archivo);

  for (int i=0; i < n_dat; i++){
    outfile << datos1[i] << endl;
  }
  //cierra el archivo.
  outfile.close(); 
}
template <class T>
void escribe(string archivo, T** datospsi, int pasosx, int pasost){
  ofstream outfile;
  //abre el archivo.
  outfile.open(archivo);

  for (int i=0; i < pasost; i++){
    for (int j=0; j < pasosx; j++){
      outfile << datospsi[i][j] << "\t";
    }
    outfile << endl;
  }
  //cierra el archivo.
  outfile.close(); 
}

void ftcs(float** psi ,float deltax, float deltat, int pasost, int pasosx, float D, float s);


int main(){
    float D = 1;
    float s = 1;
    float Nx = 30;
    float psimin = 0;
    float psimax = 0;
    float tmin = 0;
    float tmax = 1;
    
    float xmin = -1; //En psi 1
    float xmax = 1; //En psi 2
    
    float deltat = 0.0001;
    float deltax = (xmax - xmin)/Nx;

    //psi(t=0)=0
    int pasost = (tmax - tmin)/deltat;
    int pasosx = Nx;

    float* t = new float[pasost];
    float** psi = new float*[pasost]; //respuesta que quiero

    ftcs(psi,deltax,deltat,pasost,pasosx,D,s);

    escribe("tiempo.txt", t, pasost);
    escribe("n30.txt", psi, pasosx, pasost);
    // escribe() 
    // float** G = new float*[pasosx];
    // float** I = new float*[pasosx];

    // for(int i = 0; i< pasosx ; i++){

    //   G[i] = new float[pasosx];
    //   I[i] = new float[pasosx];

    //   for(int j = 0; j<pasosx; j++){
    //     if(i==j){
    //       I[i][j] = 1;
    //     }
    //     else{
    //       I[i][j] = 0;
    //     }
    //   }
    // }


    delete[] t;
    delete[] psi;

    return 0;
}

// float s(float x){
//   return x;
// }

void ftcs(float** psi ,float deltax, float deltat, int pasost, int pasosx, float D, float s){
  for(int n = 0; n< pasost; n++){
    psi[n] = new float[pasosx];
    for(int j = 0; j < pasosx ; j++){
      if(n==0){
        psi[n][j] = 0;
      }
      else if(j==0 || j==pasosx-1){
        psi[n][j] = 0;
      }
      else{
        psi[n][j] = psi[n-1][j] + (D*deltat) * (psi[n][j+1] - 2*psi[n][j] + psi[n][j-1])/pow(deltax,2) + deltat*s;
      }
      
    }
  } 
}