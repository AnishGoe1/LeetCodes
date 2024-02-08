/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void swap(int* a, int* b){
     int temp = *a;
     *a = *b;
     *b = temp;
 }

 void backtrack(int* nums, int numsSize, int*** arr, int* returnSize, int** returnColumnSizes, int index){
     if(index == numsSize - 1){
         (*returnSize)++;
         *arr = (int**)realloc(*arr, sizeof(int*) * (*returnSize));
         (*returnColumnSizes)[*returnSize - 1] = numsSize;
         (*arr)[*returnSize - 1] = (int*)malloc(sizeof(int) * numsSize);
         for(int i=0; i<numsSize; i++){
             (*arr)[*returnSize - 1][i] = nums[i];
         }
         return;
     }
     for(int i=index; i<numsSize; i++){
         swap(nums+index, nums+i);
         backtrack(nums, numsSize, arr, returnSize, returnColumnSizes, index + 1);
         swap(nums+index, nums+i);
     }
 }

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 1;
    for(int i=1; i<=numsSize; i++) (*returnSize) *= i;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int)); 
    *returnSize = 0;
    int **arr = (int**)malloc(sizeof(int*));
    backtrack(nums, numsSize, &arr, returnSize, returnColumnSizes, 0);
    return arr;
}




void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void generatePermutations(int* nums, int numsSize, int index, int** result, int* returnSize, int** returnColumnSizes) {
    if (index == numsSize) {
        result[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], nums, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = index; i < numsSize; i++) {
        swap(nums, index, i);
        generatePermutations(nums, numsSize, index + 1, result, returnSize, returnColumnSizes);
        swap(nums, index, i); // Backtrack
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPermutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        totalPermutations *= i;
    }

    int** result = (int**)malloc(totalPermutations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalPermutations * sizeof(int));
    *returnSize = 0;

    generatePermutations(nums, numsSize, 0, result, returnSize, returnColumnSizes);
    return result;
}




void _swap ( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void _solution ( int *nums, int numsSize, int *curIndex, int **result, int *returnSize )
{
    if ( *curIndex == numsSize )
    {
        int **p = ( result + *returnSize );
        *p = ( int * )malloc( numsSize * sizeof( int ) );
        memcpy( *p, nums, numsSize * sizeof( int ) );
        ++( *returnSize );
        return;
    }

    for ( int i = *curIndex; i < numsSize; ++i )
    {
        _swap( nums + i, nums + ( *curIndex )++ );
        _solution( nums, numsSize, curIndex, result, returnSize );
        --( *curIndex );
        _swap( nums + i, nums + *curIndex );
    }
}

int** permute ( int *nums, int numsSize, int *returnSize, int **returnColumnSizes )
{
    int size = 1;
    for ( int i = 2; i <= numsSize; ++i )
        size *= i;

    *returnColumnSizes = ( int * )malloc( size * sizeof( int ) );
    for ( int i = 0 ; i < size; ++i )
        *( *returnColumnSizes + i ) = numsSize;

    int **result = ( int ** )malloc( size * sizeof( int * ) );
    *returnSize = 0;
    int curIndex = 0;
    _solution( nums, numsSize, &curIndex, result, returnSize );

    return result;

}
