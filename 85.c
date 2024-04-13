int maximalRectangle(char** matrix, int rowSize, int* colSize){
    if (rowSize == 0 || *colSize == 0)
        return 0;

    int* height = (int*)malloc(sizeof(int) * (*colSize));
    int* left = (int*)malloc(sizeof(int) * (*colSize));
    int* right = (int*)malloc(sizeof(int) * (*colSize));
    int count = 0;

    for (int i = 0; i < *colSize; i++) {
        height[i] = 0;
        left[i] = 0;
        right[i] = *colSize;
    }

    for (int i = 0; i < rowSize; i++) {
        int currentLeft = 0, currentRight = *colSize;
        for (int j = 0; j < *colSize; j++) {
            if (matrix[i][j] == '1') {
                height[j]++;
                left[j] = left[j] > currentLeft ? 
                          left[j] : currentLeft;
            } else {
                height[j] = 0;
                left[j] = 0;
                currentLeft = j + 1;
            }
        }

        for (int j = *colSize - 1; j >= 0; j--) {
            if(matrix[i][j] == '1')
                right[j] = right[j] < currentRight ? 
                           right[j] : currentRight;
            else {
                right[j] = *colSize;
                currentRight = j;
            }
        }

        for (int j = 0; j < *colSize; j++)
            count = count > (right[j] - left[j]) * height[j] ? 
                    count : (right[j] - left[j]) * height[j];
    }

    free(height);
    free(left);
    free(right);

    return count;
}
