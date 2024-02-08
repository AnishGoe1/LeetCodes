int get_avg(int i, int j, const int **img, int rows, int cols) {
    int sum = 0;
    int count = 0;

    /* Go through each cell of the window that has center cell[i, j] */
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            int r_new = i + x;
            int c_new = j + y;

            // Boundary check
            if (r_new < 0 || r_new >= rows || c_new < 0 || c_new >= cols) {
                continue;
            }

            // Update the sum and the cell count
            sum += img[r_new][c_new];
            ++count;
        }
    }

    return sum / count;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int rows = imgSize;
    int cols = imgColSize[0];

    /* Allocate the memory for output result */
    int **result = (int **)calloc(rows, sizeof(int *));
    if (result == NULL) {
        return NULL;
    }

    /* Update the return size and allocate the memory for column sizes */
    *returnSize = rows;
    *returnColumnSizes = (int *)calloc(rows, sizeof(int));
    if (*returnColumnSizes == NULL) {
        free(result);
        return NULL;
    }

    /* Allocate each row of the output result */
    for (int i = 0; i < rows; ++i) {
        result[i] = (int *)calloc(cols, sizeof(int));
        if (result[i] == NULL) {
            for (int j = 0; j < i; ++j)
                free(result[j]);
            free(result);
            free(*returnColumnSizes);
            return NULL;
        }
        (*returnColumnSizes)[i] = cols;
    }

    /* Compute the average of the cells in the window */
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = get_avg(i, j, img, rows, cols);
        }
    }

    return result;
}
