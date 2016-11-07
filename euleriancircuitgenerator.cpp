#include <cstdlib>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
  int orden = atoi(argv[1]);

  //Esto crea la matrix
  int **m;
  m = new int* [orden];//Se hace un arreglo con la cantidad de filas que ingreso el usuario
  for(int c = 0; c < orden; c++) {
      m[c] = new int[orden]; //Crea un arreglo nuevo en cada espacio de memoria del arreglo anterior, columnas
      for(int r = 0; r <orden; r++)
        m[c][r] = 0;

  }


  /*
    AQUÍ VA EL CODIGO DANI
  */



  //Libera los arreglos dentro del arreglo principal.
  for (int i = 0; i < orden; i++){
      delete[] m[i];
  }
  delete [] m;// Libera el arreglo principal
  return 0;
}
