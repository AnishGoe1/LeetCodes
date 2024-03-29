int maxSumAfterPartitioning(int* arr, int arrSize, int k){
    int n = arrSize;
    int* dp = malloc((n+1) * sizeof(int));
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int M = arr[i];
        dp[i+1] = arr[i] + dp[i];
        for(int j = i-1; j >=fmax(0, i-k+1); j--){
            M = fmax(M, arr[j]);
            dp[i+1] = fmax(dp[i+1], M*(i-j+1) + dp[j]);
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
}
