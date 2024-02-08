#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int cmp(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}
int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int **ones = (int **)malloc(sizeof(int *) * matrixSize), ans = 0;
    for (int i = 0; i < matrixSize; i++) {
        ones[i] = (int *)malloc(sizeof(int) * matrixColSize[i]);
    }
    for (int i = 0; i < matrixColSize[0]; i++) {
        for (int j = matrixSize - 1, cnt = 0; j >=0; j--) {
            if (matrix[j][i] == 1) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            ones[j][i] = cnt;
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        qsort(ones[i], matrixColSize[i], sizeof(int), cmp);
        for (int j = 0, height = INT_MAX; j < matrixColSize[i]; j++) {
            height = MIN(height, ones[i][j]);
            ans = MAX(ans, height * (j + 1));
        }
        free(ones[i]);
    }
    free(ones);
    return ans;
}
