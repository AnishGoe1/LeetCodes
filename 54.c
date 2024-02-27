int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    * returnSize = matrixSize * (* matrixColSize);
    int * res = calloc(*returnSize, sizeof(int));
    int r = 0, c = -1;
    int r_max = matrixSize-1, c_max = * matrixColSize-1;
    int r_min = 1, c_min = 0;
    for (int i = 0; i < *returnSize;){
        while ((c + r) <= (r_max + c_max)){
            if (c < c_max) c++;
            else if (r < r_max) r++;
            else break;
            res[i++] = matrix[r][c];
        }
        if (i == *returnSize) break;
        r_max--;
        c_max--;
        while ((c + r) >= (r_min + c_min)){
            if (c > c_min) c--;
            else if (r > r_min) r--;
            else break;
            res[i++] = matrix[r][c];
        }
        r_min++;
        c_min++;
    }
    return res;
}
