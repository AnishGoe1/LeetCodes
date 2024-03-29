
int bisect_left(int *nums, int n, int target, bool *found)
{
    int lo, hi;

    *found = false;
    lo = 0;
    hi = n - 1;
    
    if (n == 0)
        return -1;
    
    if (n == 1 && nums[0] == target) {
        *found = true;
        return 0;
    }
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;

        if (target <= nums[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    assert(lo == hi);
    if (nums[lo] == target)
        *found = true;
    return lo;
}

#define DIVUP(a, b) (((a) + (b) - 1) / (b))

int bisect_right(int *nums, int n, int target, bool *found)
{
    int lo, hi;
    
    *found = false;
    lo = 0;
    hi = n - 1;
    
    if (n == 0)
        return -1;
    
    if (n == 1 && nums[0] == target) {
        *found = true;
        return 0;
    }
    
    while (lo < hi) {
        int mid = DIVUP(lo + hi, 2);

        if (nums[mid] <= target) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    assert(lo == hi);
    if (nums[lo] == target)
        *found = true;
    return lo;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    bool found;

    ret[0] = bisect_left(nums, numsSize, target, &found);
    if (!found)
        ret[0] = -1;
    
    ret[1] = bisect_right(nums, numsSize, target, &found);
    if (!found)
        ret[1] = -1;
    
    return ret;
}
