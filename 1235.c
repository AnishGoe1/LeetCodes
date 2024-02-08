int binSearch(int** check, int start, int end, int target) {
    int mid = 0;

    while(start < end) {
        mid = start + ((end - start) / 2);
        if(check[mid][0] < target) start = mid + 1;
        else end = mid;
    }

    return start;
}

int cmp1(const void* a, const void* b) {
    int *A = *(int**)a;
    int *B = *(int**)b;

    return A[0] - B[0];
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
    int** check = malloc(startTimeSize * sizeof(int*));
    int* dp = calloc((startTimeSize + 1), sizeof(int));
    int max = 0;

    for(int i = 0; i < startTimeSize; i++) {
        check[i] = malloc(2 * sizeof(int));
        check[i][0] = startTime[i];
        check[i][1] = i;
    }

    qsort(check, startTimeSize, sizeof(int*), cmp1);

    for(int i = startTimeSize - 1; i >= 0; i--) {
        dp[i] = fmax((profit[check[i][1]] + dp[binSearch(check, i, startTimeSize, endTime[check[i][1]])]), dp[i+1]);
    }

    return dp[0];
}
