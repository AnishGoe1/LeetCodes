int maxProduct(int nums[], int numsSize) {
    int ans = 0;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            ans = (ans > (nums[i] - 1) * (nums[j] - 1)) ? ans : (nums[i] - 1) * (nums[j] - 1);
        }
    }
    
    return ans;
}
