int isEmpty(int **graph, int order);
void findEulerianRecursive(int **graph, int n, int row,int col);

int indexPath=0;
int *path;

//graph[row][col]
void eulerianPath(int **matrix,int order) {
  path =(int *) malloc (order*sizeof(int));
  findEulerianRecursive(matrix,order,0,0);
}

void findEulerianRecursive(int **graph, int n, int row,int col){
  //printf("%d \n", row);
  mostrar(graph,n);
  if( isEmpty(graph,n) == 1)
    mostrar(graph,n);
  else if(graph[row][col]==1){
    graph[row][col]=0;
    graph[col][row]=0;
    path[indexPath]=col;
    indexPath++;
    findEulerianRecursive(graph, n, col, 0);
  }
  else
    findEulerianRecursive(graph, n, row, col+1);
}

int isEmpty(int **graph, int order){
  for (size_t row = 0; row < order; row++)
    for (size_t col = 0; col < order; col++)
      if (graph[row][col] == 1 )
        return 0;
    return 1;
}
