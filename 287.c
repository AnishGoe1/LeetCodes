int findDuplicate(int* nums, int numsSize) {
    int slow = 0, fast = 0;

    // find the intersection:
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // now loop one by one until they meet:
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
