void mostrar(int **matrix, int order);
void incluir(int a, int b, int **matrix, int order);
void eliminar(int a, int b, int **matrix, int order);
int pertenece(int a, int b, int **matrix, int order);
int degreeVertex(int a, int **matrix, int order);
int imparV(int *impar, int **matrix, int order); //Guarda las aristas de grado impar en el arreglo impar y devuelve el largo de este arreglo.

void mostrar(int **matrix, int order){
  for (int row=0; row<order; row++){
    for(int columns=0; columns<order; columns++)
         printf("%d ", matrix[row][columns]);
    printf("\n");
  }
  printf("\n");
}


void incluir(int a, int b, int **matrix, int order){
  matrix[a][b]= 1;
  matrix[b][a]=1;
}

void eliminar(int a, int b, int **matrix, int order){
  matrix[a][b]= 0;
  matrix[b][a]= 0;
}


//devueve 1 si pertenece, 0 sino.
int pertenece(int a, int b, int **matrix, int order){
  if(matrix[a][b] == 1)
    return 1;
  else
    return 0;
}

//Cuenta la cantidad de 1 en una fila, la cantidad total de 1 es el grado del vertice.
int degreeVertex(int a, int **matrix, int order){
    int count = 0;
    for( int c = 0; c < order; c++){
      if( matrix[a][c] == 1)
        count++;
    }
    return count;
}

//Guarda las aristas de grado impar en el arreglo impar y devuelve el largo de este arreglo.
int imparV(int *impar, int **matrix, int order){
  int degree;
  int count=0;
  for(int i = 0; i < order; i++){
    degree = degreeVertex(i,matrix,order);
    if(degree % 2 != 0){
      impar[count]=i;
      count++;
    }
  }
  return  count;
}


/*
int main(int argc, char const *argv[]) {
  int order = atoi(argv[1]);

  //Crea el arreglo impar, su máximo se elementos es la cantidad de vertices que hay en el grafo.
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

  incluir(1-1,2-1,matrix,order);
  incluir(1-1,3-1,matrix,order);
  incluir(1-1,4-1,matrix,order);
  incluir(2-1,3-1,matrix,order);
  incluir(3-1,4-1,matrix,order);
  mostrar(matrix,order);
  imparV(impar,matrix,order);
  for(int i = 0; i<2; i++)
    cout<<impar[i]<<" ";
  cout<<endl;


  //Libera los arreglos dentro del arreglo principal.
  for (int i = 0; i < order; i++){
      delete[] matrix[i];
  }
  delete [] matrix;// Libera el arreglo principal
  delete [] impar;
  return 0;
}
*/
