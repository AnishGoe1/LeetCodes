int compareNums(const void* a, const void* b) {
    return *((int*) a) - *((int*) b);
}

long long largestPerimeter(int* nums, int numsSize) {
    const int n = numsSize;

    qsort(nums, n, sizeof(nums[0]), compareNums);

    long long sum = nums[0] + nums[1];
    long long per = -1;
    
    for (int i = 2; i < n; i++) {
        if (nums[i] < sum) {
            per = sum + nums[i];
        }

        sum += nums[i];
    }

    return per;
}
