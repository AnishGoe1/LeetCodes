int min(int a , int b){
    if(a<b){
        return a;
    }
    return b;
}
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i ;
    int j ;
    for( i = 0 ;i<gridSize;i++){
        for( j = 0;j<(*gridColSize);j++){
            if(i-1>=0 && j-1>=0){
                grid[i][j] += min(grid[i-1][j] , grid[i][j-1]);
            }
            else if(i-1 >= 0){
                grid[i][j] += grid[i-1][j];
            }
            else if(j-1 >= 0){
                grid[i][j] += grid[i][j-1];
            }
        }
    }
    return grid[i-1][j-1];
}
