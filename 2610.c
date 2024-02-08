/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int existsInRow(int* row, int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (row[i] == element) {
            return 1; // Element exists in the row
        }
    }
    return 0; // Element does not exist in the row
}

int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Initialize variables
    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    // Iterate through the elements of nums
    for (int i = 0; i < numsSize; ++i) {
        int found = 0;

        // Check if the current element exists in any row of the result array
        for (int j = 0; j < *returnSize; ++j) {
            if (!existsInRow(result[j], (*returnColumnSizes)[j], nums[i])) {
                // Add the element to the current row
                result[j] = realloc(result[j], ((*returnColumnSizes)[j] + 1) * sizeof(int));
                result[j][(*returnColumnSizes)[j]] = nums[i];
                (*returnColumnSizes)[j]++;
                found = 1;
                break;
            }
        }

        // If the element is not found in any row, create a new row
        if (!found) {
            // Increase the size of the result array
            result = realloc(result, (*returnSize + 1) * sizeof(int*));
            (*returnColumnSizes) = realloc((*returnColumnSizes), (*returnSize + 1) * sizeof(int));

            // Create a new row and add the element
            result[*returnSize] = malloc(sizeof(int));
            result[*returnSize][0] = nums[i];
            (*returnColumnSizes)[*returnSize] = 1;

            // Increment the size of the result array
            (*returnSize)++;
        }
    }

    return result;
}
