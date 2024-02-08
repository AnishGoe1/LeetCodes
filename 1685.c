int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for(int i=0;i<numsSize;i++){
        result[i]=0;
        for(int j=0;j<numsSize;j++){
            result[i]=result[i]+abs(nums[i]-nums[j]);
        }
    }
    return result;
}





int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int* prefixSum = (int*)malloc(numsSize * sizeof(int));
    int* suffixSum = (int*)malloc(numsSize * sizeof(int));
    prefixSum[0] = nums[0];
    suffixSum[numsSize - 1] = nums[numsSize - 1];
    for (int i = 1; i < numsSize; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
        suffixSum[numsSize - i - 1] = suffixSum[numsSize - i] + nums[numsSize - i - 1];
    }
    for (int i = 0; i < numsSize; ++i) {
        int currentAbsoluteDiff = ((nums[i] * i) - prefixSum[i]) + (suffixSum[i] - (nums[i] * (numsSize - i - 1)));
        result[i] = currentAbsoluteDiff;
    }
    return result;
}
