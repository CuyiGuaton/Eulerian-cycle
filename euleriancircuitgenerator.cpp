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

  mostrar(matrix,n);


  int largo = imparV(impar,matrix,n);

  /* Muestra impar, borrar después */
  cout<<"largo = "<<largo<<endl<<"Impar= {";
  for (size_t i = 0; i < largo; i++) {
    cout<<impar[i]<<"  ";
  }
  cout<<"}"<<endl<<endl;
  /* borrar hasta aquí */


while(largo != 0){
  b=impar[largo-1]; //elige el último elemento de impar
  a=impar[largo-2]; //elige el penúltimo elemento de impar
  cout<<"largo = "<<largo<<endl;
  cout<<"b = "<<b<<endl;
  cout<<"a = "<<a<<endl;
  if(pertenece(a,b,matrix,n) != 1)
    incluir(a,b,matrix,n);
  else
    if (b != a+1)
      eliminar(a,b,matrix,n);
    else{
      //c = a+2 +(rand()% n-3 + 1) % n; //C = a+2 +rand(1, n-3) mod n
      c=a;
      cout<<"c = "<<c<<endl;
      if (pertenece(a,c,matrix,n) ==1 )
        eliminar(a,c,matrix,n);
      else
        incluir(a,c,matrix,n);
      if (pertenece(b,c,matrix,n) ==1 )
        eliminar(b,c,matrix,n);
      else
        incluir(b,c,matrix,n);
    }
  largo=largo-2;
}

  mostrar(matrix,n);

  //Libera los arreglos dentro del arreglo principal.
  for (int i = 0; i < n; i++){
      delete[] matrix[i];
  }
  delete [] matrix;// Libera el arreglo principal
  delete [] impar;
  return 0;
}
