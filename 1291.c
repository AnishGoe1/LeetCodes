int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int* sequentialDigits(int low, int high, int* returnSize){
    int* res = NULL;
    *returnSize = 0;
    for (int i = 1; i <= 9; i++){
        int num = i;
        for (int j = i + 1; j <= 9; j++){
            num = 10 * num + j;
            if (low <= num && num <= high){
                (*returnSize)++;
                res = realloc(res, sizeof(int) * (*returnSize));
                res[(*returnSize) - 1] = num;
            }
        }
    }
    if (!res) return NULL;
    qsort(res, *returnSize, sizeof(int), cmp);
    return res;
}
