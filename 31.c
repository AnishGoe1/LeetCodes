int cmpfunc(const void* a, const void* b)
{
    if (*(int*) a > *(int*) b) return 1;
    if (*(int*) b > *(int*) a) return -1;
    return 0;
}

void nextPermutation(int* nums, int numsSize)
{
    int i,j,temp;
    for (i=numsSize-1; i>0; i--)
    {
        if (nums[i]>nums[i-1])
        {
            qsort(nums+i,numsSize-i,sizeof(int),cmpfunc);
            int temp = nums[i-1];
            for(j=i; j<numsSize; j++)
            {
                if (nums[j]  > nums[i-1]) 
                {
                    nums[i-1] = nums[j];
                    nums[j] = temp;
                    return;
                }
            }
        }
    }
    
    i = 0;
    j = numsSize-1;
    while (i<j)
    {
        temp = nums[i];
        nums[i++] = nums[j];
        nums[j--] = temp;        
    }

}
