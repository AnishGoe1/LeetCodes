int block(int n) {
    if(n) return n;
    else return 0;
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    
    for(int i = 0; i < obstacleGridSize; i++) {
        for(int j = 0; j < *obstacleGridColSize; j++) {
            if(obstacleGrid[i][j]) {
                obstacleGrid[i][j] = 0;
            }
            else {
                obstacleGrid[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < obstacleGridSize; i++) {
        for(int j = 0; j < *obstacleGridColSize; j++) {
            if(!obstacleGrid[i][j]) continue;

            if(i && j) {
                obstacleGrid[i][j] = block(obstacleGrid[i-1][j]) + block(obstacleGrid[i][j-1]);
            }
            else if(i) {
                obstacleGrid[i][j] = block(obstacleGrid[i-1][j]);
            }
            else if(j) {
                obstacleGrid[i][j] = block(obstacleGrid[i][j-1]);
            }
        
        }
    }
    
    return obstacleGrid[obstacleGridSize - 1][(*obstacleGridColSize) - 1];
}
