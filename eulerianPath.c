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

  if(graph[row][col]==1){
    graph[row][col]=0;
    graph[col][row]=0;
    path[indexPath]=col;
    indexPath++;
    findEulerianRecursive(graph, n, col, 0);
  }
  else
    findEulerianRecursive(graph, n, row, col+1);
}
