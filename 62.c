int memo[101][101];

int getRoutes(int y, int x, int m, int n)
{
    if (y == m || x == n)
        return 0;
    if (y == m - 1 && x == n - 1)
        return 1;
    
    if (memo[y][x] != -1)
        return memo[y][x];

    int right = getRoutes(y, x + 1, m, n);
    int down = getRoutes(y + 1, x, m, n);
    memo[y][x] = right + down;
    return memo[y][x];
}

int uniquePaths(int m, int n){
    memset(memo, -1, sizeof(memo));
    return getRoutes(0, 0, m, n);
}






int uniquePaths(int m, int n) {
    if(n ==1 || m == 1)
            return 1;
    int matrix[m][n];
        for(int i=1; i<m; i++){
            matrix[i][0] = 1;
        }
        for(int j=1; j<n; j++){
            matrix[0][j] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
}
