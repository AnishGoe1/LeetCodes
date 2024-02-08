int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int* row_sum = (int*)malloc(gridSize * sizeof(int));
    int* col_sum = (int*)calloc(*gridColSize, sizeof(int));
    for (int i = 0; i < gridSize; ++i) {
        row_sum[i] = 0;
        for (int j = 0; j < *gridColSize; ++j) {
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            grid[i][j] = 2 * (row_sum[i] + col_sum[j]) - gridSize - *gridColSize;
        }
    }
    free(row_sum);
    free(col_sum);
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return grid;
}
