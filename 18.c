int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int** ans = NULL;
    *returnSize = 0;

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            long long newTarget = (long long)target - nums[i] - nums[j];
            int low = j + 1, high = numsSize - 1;

            while (low < high) {
                long long sum = nums[low] + nums[high];
                if (sum < newTarget) {
                    low++;
                } else if (sum > newTarget) {
                    high--;
                } else {
                    (*returnSize)++;
                    ans = (int**)realloc(ans, (*returnSize) * sizeof(int*));
                    ans[*returnSize - 1] = (int*)malloc(4 * sizeof(int));
                    ans[*returnSize - 1][0] = nums[i];
                    ans[*returnSize - 1][1] = nums[j];
                    ans[*returnSize - 1][2] = nums[low];
                    ans[*returnSize - 1][3] = nums[high];
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                }
            }
        }
    }

    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 4;
    }

    return ans;
}







int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ans = NULL;
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            long long newTarget = (long long)target - nums[i] - nums[j];
            int low = j + 1, high = numsSize - 1;

            while (low < high) {
                long long sum = (long long)nums[low] + nums[high];
                if (sum < newTarget) {
                    low++;
                } else if (sum > newTarget) {
                    high--;
                } else {
                    (*returnSize)++;
                    ans = (int**)realloc(ans, (*returnSize) * sizeof(int*));
                    ans[*returnSize - 1] = (int*)malloc(4 * sizeof(int));
                    ans[*returnSize - 1][0] = nums[i];
                    ans[*returnSize - 1][1] = nums[j];
                    ans[*returnSize - 1][2] = nums[low];
                    ans[*returnSize - 1][3] = nums[high];
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                }
            }
        }
    }

    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 4;
    }

    return ans;
}






int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ans = NULL;
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            long long newTarget = (long long)target - nums[i] - nums[j];
            int low = j + 1, high = numsSize - 1;

            while (low < high) {
                long long sum = (long long)nums[low] + nums[high];
                if (sum < newTarget) {
                    low++;
                } else if (sum > newTarget) {
                    high--;
                } else {
                    (*returnSize)++;
                    ans = (int**)realloc(ans, (*returnSize) * sizeof(int*));
                    ans[*returnSize - 1] = (int*)malloc(4 * sizeof(int));
                    ans[*returnSize - 1][0] = nums[i];
                    ans[*returnSize - 1][1] = nums[j];
                    ans[*returnSize - 1][2] = nums[low];
                    ans[*returnSize - 1][3] = nums[high];
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                }
            }
        }
    }

    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 4;
    }

    return ans;
}
