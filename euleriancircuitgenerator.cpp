#include <cstdlib>
#include <iostream>
#include "funcions.cpp"
using namespace std;



int main(int argc, char const *argv[]) {
  int order = atoi(argv[1]);

  //Crea el arreglo que guarda la cantidad de vertices impares (de grado impar)
  int *impar;
  impar =new int[0];

  //Esto crea la matrix
  int **matrix;
  matrix = new int* [order];
  for(int c = 0; c < order; c++) {
      matrix[c] = new int[order];
      for(int r = 0; r <order; r++)
        matrix[c][r] = 0;

  }


  /*
    codigo psudocigosada
  
  */



  //Libera los arreglos dentro del arreglo principal.
  for (int i = 0; i < order; i++){
      delete[] matrix[i];
  }
  delete [] matrix;// Libera el arreglo principal
  delete [] impar;
  return 0;
}
