#include <cstdlib>
#include <iostream>
#include "functions.cpp"
using namespace std;


int main(int argc, char const *argv[]) {
  int a;
  int b;
  int c;

  //Da el orden de la matrix
  int n = atoi(argv[1]);
  float p = atof(argv[2]);

  //Crea el arreglo que guarda la cantidad de vertices impares (de grado impar)
  int *impar;
  impar =new int[0];

  //Esto crea la matrix
  int **matrix;
  matrix = new int* [n];
  for(int c = 0; c < n; c++) {
      matrix[c] = new int[n];
      for(int r = 0; r <n; r++)
        matrix[c][r] = 0;

  }
  cout<<p<<endl;


  //Genera un grafo aleatorio
  for(a=0; a < n-1 ; a++){
    incluir(a,a+1,matrix,n);
    for(b=a+2 ; b<n ; b++)
      if( rand()%100 + 1 < p*100 )
        incluir(a,b,matrix,n);
  }

  int largo = imparV(impar,matrix,n);
  cout<<largo<<endl<<" Impar= {";
  for (size_t i = 0; i < largo; i++) {
    cout<<impar[i]<<"  ";
  }
  cout<<"}"<<endl;

  //Libera los arreglos dentro del arreglo principal.
  for (int i = 0; i < n; i++){
      delete[] matrix[i];
  }
  delete [] matrix;// Libera el arreglo principal
  delete [] impar;
  return 0;
}
