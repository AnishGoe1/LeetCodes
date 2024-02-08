/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int vals_cnt = 0;
    int max_diag = 0;
    /* Find max diagnal */
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsColSize[i]; ++j) {
            int diag = i + j;
            max_diag = fmax(max_diag, diag);
            ++vals_cnt;
        }
    }
    /* Allocate memory for 2d matrix and the size array */
    int **cols_vals = (int **)calloc(max_diag + 1 , sizeof(int *));
    int *cols_size = (int *)calloc(max_diag + 1, sizeof(int));
    int max_cols = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsColSize[i]; ++j) {
            // Get the column index
            int diag = i + j;   
            // Dynamic memory allocation:
            //      Allocate memory for NULLs
            //      Resize memory for new data
            if (cols_size[diag] == 0) {
                cols_vals[diag] = (int *)malloc(sizeof(int));
                max_cols++;
            } else {
                cols_vals[diag] = (int *)realloc(cols_vals[diag], (cols_size[diag] + 1) * sizeof(int));
            }
            // Add the value to the place
            cols_vals[diag][cols_size[diag]++] = nums[i][j];
        }
    }
    *returnSize = vals_cnt;
    /* Add columns of value to result */
    int *result = (int *)malloc(vals_cnt * sizeof(int));
    int idx = 0;
    for (int i = 0; i < max_cols; ++i) {
        for (int j = cols_size[i] - 1; j >= 0; --j) {
            result[idx++] = cols_vals[i][j];
        }
    }
    free(cols_vals);
    free(cols_size);

    return result;
}
