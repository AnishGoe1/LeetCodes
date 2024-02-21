int factorial(int n)
{
    int res;

    for (res = 1; n > 1; n--)
        res *= n;

    return res;
}

int cmpfn(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}

int** permuteInt(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int origCellWidth, int size)
{
    int i;
    int ri = 0;

    int ** res = malloc(size * sizeof(int*));

    int * retCellSize = *returnColumnSizes;

    if (numsSize == 1)
    {
        retCellSize[0] = origCellWidth;
        res[0] = malloc(sizeof(int) * origCellWidth);
        res[0][0] = *nums;
        * returnSize = 1;
        return res;
    }

    int* temp = malloc(sizeof(int) * numsSize);

    for (i = 0; i < numsSize; i++)
    { 
        if (i+1 < numsSize && (nums[i] == nums[i+1]))
            continue;

        memcpy(temp, nums, sizeof(int) * numsSize);

        if (i != 0)
        {
            int bkup = temp[i];
            memmove(temp+1, temp, sizeof(int) * i);
            temp[0] = bkup;
        }

        int ** perm = permuteInt(temp+1, numsSize - 1, returnSize, returnColumnSizes, origCellWidth, size);

        for (int j = 0; j < (*returnSize); j++)
        {
            res[ri] = perm[j];            
            memmove(&res[ri][1], perm[j], sizeof(int) * (numsSize - 1) );
            res[ri][0] = temp[0];
            retCellSize[ri++] = origCellWidth;
        }
    }

    * returnSize = ri;
    free(temp);
    return res;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    * returnColumnSizes = NULL;
    * returnSize = 0;

    qsort(nums, numsSize, sizeof(int), cmpfn);

    int count = 1;
    int denom = 1;
    for (int i = 0; i < numsSize; i++)
    { 
        if (i+1 < numsSize && (nums[i] == nums[i+1]))
            count++;
        else
        {
            denom *= factorial(count);
            count = 1;
        }
    }

    int fact = factorial(numsSize) / denom;

    *returnColumnSizes = malloc(fact * sizeof(int));

    return permuteInt(nums, numsSize, returnSize, returnColumnSizes, numsSize, fact);
}


