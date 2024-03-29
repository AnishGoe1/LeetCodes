long long countSubarrays(int* nums, int numsSize, int k) {
    int max = -1;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > max)
            max = nums[i];
    }
    int start = 0, end;
    int count_max = 0;
    long long out = 0;
    for (end = 0; end < numsSize; end++) {
        if (nums[end] == max)
            count_max++;
        while (count_max >= k) {
            out += numsSize - end;
            if (nums[start] == max) {
                count_max--;
            }
            start++;
        }
    }
    return out;
}
