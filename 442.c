/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int temp; *returnSize=0;
    for(int i=0; i<numsSize; i++) { /* cyclic sort, skip duplicates */
        if(nums[i]==(i+1)){ continue; }
        if(nums[i]==nums[nums[i]-1]) { (*returnSize)++; continue; }
        temp=nums[i]; nums[i]=nums[temp-1]; nums[temp-1]=temp; i--;
    }

    int* result=malloc(*returnSize*sizeof(int)); *returnSize=0;
    for(int i=0; i<numsSize; i++)
    { if(nums[i]!=(i+1)){ result[(*returnSize)++]=nums[i]; } }

    return result;
}
