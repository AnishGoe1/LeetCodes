int searchInsert(int* nums, int numsSize, int target){
 int i;
    for (i = 0; i < numsSize  ; i++)
    {
        if (target<=nums[i])
        break;
        
    }
    return i;
}
