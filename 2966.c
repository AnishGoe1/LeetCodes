/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    if (numsSize % 3 != 0) {
        return NULL;
    }

    /* Initialize variables */
    *returnSize = numsSize / 3;
    qsort(nums, numsSize, sizeof(int), cmp);

    int **result = (int **)calloc(*returnSize, sizeof(int *));
    if (result == NULL) {
        exit(-1);
    }

    int index = 0;
    for (int i = 2; i < numsSize; i += 3) {
        if (nums[i] - nums[i - 2] > k) {
            // reset result
            for (int j = 0; j < *returnSize; ++j) {
                free(result[j]);
            }
            free(result);
            *returnSize = 0;
            return NULL;
        }

        int *temp = (int *)malloc(3 * sizeof(int));
        if (temp == NULL) {
            for (int j = 0; j < *returnSize; ++j) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
        temp[0] = nums[i - 2];
        temp[1] = nums[i - 1];
        temp[2] = nums[i - 0];

        result[index++] = temp;
        temp = NULL;
    }

    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    if (*returnColumnSizes == NULL) {
        for (int j = 0; j < *returnSize; ++j) {
            free(result[j]);
        }
        free(result);
        return NULL;
    }
    
    for (int i = 0; i < (*returnSize); ++i) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
