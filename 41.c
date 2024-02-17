int firstMissingPositive(int* nums, int numsSize){
int i;
int* pos_range = malloc((numsSize+2) * sizeof(int));
for (i=0; i<=numsSize+1; i++) pos_range[i]=0;
for (i=0; i<numsSize; i++)
    if ((nums[i]>0) && (nums[i]<numsSize+1))
        pos_range[nums[i]]++;
for (i=1; i<=numsSize+1; i++)
    if (pos_range[i]==0) return i;

// would only get here if all numbers were non-positive...
return 1;
}
