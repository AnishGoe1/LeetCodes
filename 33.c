

int search(int* nums, int numsSize, int target)
{
    int lo, hi;
    
    for (lo = 0, hi = numsSize - 1; lo <= hi;) {
        int mid = (lo + hi) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[lo] <= nums[mid]) {
            // we are on the left of the peak
            if (nums[lo] <= target && target < nums[mid]) {
                // go left
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            // we are on the right of the peak
            if (nums[mid] < target && target <= nums[hi]) {
                // go right
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
    }

    return -1;
}
