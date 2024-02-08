void binSearch(int* dp, int start, int end, int pl) {
    int mid = 0;

    while(start + 1 < end) {
        mid = (start + end)/2;
        if(dp[mid] < pl) start = mid;
        else end = mid;
    }

    dp[end] = pl;
}

int lengthOfLIS(int* nums, int numsSize) {
    int* arr = calloc((numsSize), sizeof(int));
    int idx = 0;
    for(int i = 0; i < numsSize; i++) {
        if(idx == 0 || nums[i] > arr[idx-1]) arr[idx++] = nums[i];
        else {
            if(arr[0] < nums[i]) binSearch(arr, 0, idx - 1, nums[i]);
            else arr[0] = nums[i];
        }
    }
    return idx;
}
    
