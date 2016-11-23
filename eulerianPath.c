void showPath();
int isEmpty(int **graph, int order);
void findEulerianRecursive(int **graph, int n, int row,int col);

int indexPath=0;
int *path;

//Funcion que se encarga iniciar la función recursiva
void eulerianPath(int **matrix,int order) {
  path =(int*)calloc(order, sizeof(int));
  findEulerianRecursive(matrix,order,0,0);
}

//Recorre la matrix cambiando los 1 por 0 cuando es necesario.
void findEulerianRecursive(int **graph, int n, int row,int col){
  if(col >  n) //Si se llego a un vertice sin aristas
    if(isEmpty(graph,n)==1){ //Si no era solo un vertice sin aristas, sino que todos los vertices no tenían arista
      path[indexPath]=row;
      indexPath++;
      showPath();
    }
    else{ // Si no encuentra una arita entre dos vertices
      graph[path[indexPath-1]][row]=1;
      graph[row][path[indexPath-1]]=1;
      indexPath--;
      findEulerianRecursive(graph, n, path[indexPath], row+1);
    }
  else
    if(graph[row][col]==1){ //Si entre los dos vertices hay una arista, se recorre y se cambia sus 1 por 0
      graph[row][col]=0;
      graph[col][row]=0;
      path[indexPath]=row;
      indexPath++;
      findEulerianRecursive(graph, n, col, 0);
    }
    else
      findEulerianRecursive(graph, n, row, col+1);
}

//Verifica que ya se haya recorrido todos los vertices
int isEmpty(int **graph, int order){
  for (size_t row = 0; row < order; row++)
    for (size_t col = 0; col < order; col++)
      if (graph[row][col] == 1 )
        return 0;
    return 1;
}


//Muestra el camino euleriano.
void showPath(){
  for (int i = 0; i <indexPath; i++) {
    printf("%i ", path[i] );
  }
  printf("\n" );
}
