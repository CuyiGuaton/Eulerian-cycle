#include <cstdlib>
#include <iostream>
using namespace std;

void mostrar(int **m, int orden);
void incluir(int a, int b, int **matrix, int order);
void eliminar(int a, int b, int **matrix, int order);
int pertenece(int a, int b, int **matrix, int order);

void mostrar(int **m, int orden){
  for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
          cout << m[i][j] << " ";
      }
      cout << endl;
  }
  cout << endl;
}

void incluir(int a, int b, int **matrix, int order){
  matrix[a][b]= 1;
  matrix[b][a]=1;
}

void eliminar(int a, int b, int **matrix, int order){
  matrix[a][b]= 0;
  matrix[b][a]= 0;
}

int pertenece(int a, int b, int **matrix, int order){
  if(matrix[a][b] == 1)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[]) {
  int order = atoi(argv[1]);

  //Esto crea la matrix
  int **matrix;
  matrix = new int* [order];
  for(int c = 0; c < order; c++) {
      matrix[c] = new int[order];
      for(int r = 0; r <order; r++)
        matrix[c][r] = 0;
  }

  incluir(2,3,matrix,order);
  mostrar(matrix,order);
  cout<<pertenece(2,3,matrix,order)<<endl;


  //Libera los arreglos dentro del arreglo principal.
  for (int i = 0; i < order; i++){
      delete[] matrix[i];
  }
  delete [] matrix;// Libera el arreglo principal
  return 0;
}
