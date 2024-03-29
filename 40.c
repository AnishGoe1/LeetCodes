int cmp(const void* a, const void* b) {
    return *(const int*) a - *(const int*) b;
}

void backtrack(int* arr, int arrSize, int tar, int start, int cidx, int* returnSize, int** returnColumnSizes, int** res, int* map, int* path) {
    if (tar == 0) {
        (*returnColumnSizes)[(*returnSize)] = cidx;
        res[(*returnSize)] = (int*) malloc(cidx * sizeof(int));
        memcpy(res[(*returnSize)], path, cidx * sizeof(int));
        (*returnSize)++;
    } else {
        for (int i = start; i < arrSize; i++) {
            if (map[arr[i]] == 0) continue;
            if (tar - arr[i] < 0) break;
            path[cidx] = arr[i];
            map[arr[i]]--;
            backtrack(arr, arrSize, tar - arr[i], i, cidx + 1, returnSize, returnColumnSizes, res, map, path);
            map[arr[i]]++;
        }
    } 
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int map[51] = {0};
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int cnt = 0, idx = 0, size = 51;
    for (int i = 0; i < candidatesSize; i++) {
        if (map[candidates[i]] == 0) cnt++;
        map[candidates[i]]++;
    }
    int* tmp = (int*) calloc(cnt, sizeof(int));
    for (int i = 1; i < 51; i++) {
        if (map[i] != 0) tmp[idx++] = i;
    }
    int** res = (int**) malloc(size * sizeof(int*));
    int* path = (int*) malloc(size * sizeof(int));
    *returnSize = 0;
    *returnColumnSizes = (int*) calloc(size, sizeof(int));
    backtrack(tmp, cnt, target, 0, 0, returnSize, returnColumnSizes, res, map, path);
    free(tmp);
    free(path);
    return res;
}
