int* findErrorNums(int* nums, int numsSize, int* returnSize){

    int *ret = (int*)malloc(sizeof(int) * 2);
    int *temp = (int*)malloc(sizeof(int) * (numsSize+1));
    
    for(int i=0; i<=numsSize; i++)
    {
        temp[i] = 0;
    }
    
    for (int i=0; i<numsSize; i++)
    {
        temp[nums[i]]++;
    }
    
    for(int i=1; i<=numsSize; i++)
    {
        if( temp[i]>1 )
            ret[0] = i;
        
        if(temp[i] == 0)
            ret[1] = i;
    }
    
    *returnSize = 2;
    return ret;
}
