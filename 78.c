void backtrack(int* nums, int numsSize, int** res, int* returnSize, int** returnColumnSizes, int* tmp, int tarSize, int cidx, int start) {
    if (cidx == tarSize) {
        (*returnColumnSizes)[(*returnSize)] = cidx;
        res[(*returnSize)] = (int*) malloc(cidx * sizeof(int));
        if (tarSize) memcpy(res[(*returnSize)], tmp, cidx * sizeof(int));
        (*returnSize)++;
    } else {
        for (int i = start; i < numsSize; i++) {
            tmp[cidx] = nums[i];
            backtrack(nums, numsSize, res, returnSize, returnColumnSizes, tmp, tarSize, cidx + 1, i + 1);
        }
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = pow(2, numsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*) malloc(size * sizeof(int));
    int** res = (int**) malloc(size * sizeof(int*));
    int* tmp = (int*) malloc(numsSize * sizeof(int));
    for (int i = 0; i <= numsSize; i++) {
        backtrack(nums, numsSize, res, returnSize, returnColumnSizes, tmp, i, 0, 0);
    }
    free(tmp);
    return res;
}
