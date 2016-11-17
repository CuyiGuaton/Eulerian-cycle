void showPath();
int isEmpty(int **graph, int order);
void findEulerianRecursive(int **graph, int n, int row,int col);

int indexPath=0;
int *path;

//graph[row][col]
void eulerianPath(int **matrix,int order) {
  path =(int*)calloc(5, sizeof(int));
  findEulerianRecursive(matrix,order,0,0);
}

void findEulerianRecursive(int **graph, int n, int row,int col){
  //printf("%d \n", row);
  if(col >  n)
    if(isEmpty(graph,n)==1){
      path[indexPath]=row;
      indexPath++;
      showPath();
    }
    else{
      graph[path[indexPath-1]][row]=1;
      graph[row][path[indexPath-1]]=1;
      indexPath--;
      findEulerianRecursive(graph, n, path[indexPath], row+1);
    }
  else
    if(graph[row][col]==1){
      graph[row][col]=0;
      graph[col][row]=0;
      path[indexPath]=row;
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

void showPath(){
  for (int i = 0; i <indexPath; i++) {
    printf("%i ", path[i] );
  }
  printf("\n" );
}
