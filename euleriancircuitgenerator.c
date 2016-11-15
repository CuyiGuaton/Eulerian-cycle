#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.cpp"


int main(int argc, char const *argv[]) {
  int a;
  int b;
  int c;
  srand(time(NULL));
  //Da el orden de la matrix
  int n = atoi(argv[1]);
  float p = atof(argv[2]);

  //Crea el arreglo que guarda la cantidad de vertices impares (de grado impar)
  int *impar;
  impar =calloc(2, sizeof(unsigned int));

  //Esto crea la matrix
  int **matrix;
  matrix = calloc(n, sizeof(int*));
  for(int c = 0; c < n; c++) {
      matrix[c] = calloc(n, sizeof(int));
      for(int r = 0; r <n; r++)
        matrix[c][r] = 0;

  }


  //Genera un grafo aleatorio
  for(a=0; a < n-1 ; a++){
    incluir(a,a+1,matrix,n);
    for(b=a+2 ; b<n ; b++)
      if( rand()%100 + 1 < p*100 )
        incluir(a,b,matrix,n);
  }

  int largo = imparV(impar,matrix,n);



while(largo != 0){
  b=impar[largo-1]; //elige el último elemento de impar
  a=impar[largo-2]; //elige el penúltimo elemento de impar
  if(pertenece(a,b,matrix,n) != 1)
    incluir(a,b,matrix,n);
  else
    if (b != a+1)
      eliminar(a,b,matrix,n);
    else{
      //c = a+2 +(rand()% n-3 + 1) % n; //C = a+2 +rand(1, n-3) mod n
      c= a-2 >= 0  ? a-2 : b+2 ;
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


  return 0;
}
