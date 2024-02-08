int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    // Check for empty matrix
    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    // Allocate memory for the transposed matrix
    int numRows = *matrixColSize;
    int numCols = matrixSize;
    int** transposedMatrix = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        transposedMatrix[i] = (int*)malloc(numCols * sizeof(int));
        (*returnColumnSizes)[i] = numCols;
    }
    // Fill in the transposed matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    *returnSize = numRows;
    return transposedMatrix;
}
