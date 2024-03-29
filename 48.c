
#define DIVUP(a, b) (((a) + (b) - 1) / (b))

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int i, j, a, b, c, d;
    
    int n = matrixSize;
    
    for (i = 0; i < DIVUP(n, 2); i++) {
        for (j = 0; j < n / 2; j++) {

            a = matrix[i][j];
            b = matrix[j][n - 1 - i];
            c = matrix[n - 1 - i][n - 1 - j];
            d = matrix[n - 1 - j][i];
            // rotate
            matrix[i][j] = d;
            matrix[j][n - 1 - i] = a;
            matrix[n - 1 - i][n - 1 - j] = b;
            matrix[n - 1 - j][i] = c;
        }
    }
}
