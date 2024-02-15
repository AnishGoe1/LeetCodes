/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** ret = NULL;
int* list = NULL;
int k = 0;
int ret_size = 0;
int* ret_col_size = NULL;
void add_ret(){
    ret[ret_size] = malloc(sizeof(int)*k);
    ret_col_size[ret_size] = k;
    memcpy(ret[ret_size++], list, sizeof(int)*k);
    //printf("%d %d\n", ret_size, k);
}

void comb(int* candidate, int size, int target, int start){
    if(!target){
        add_ret();
        return;
    }

    for(int i = start; i<size;i++){
        if(candidate[i] <= target){
            list[k++] = candidate[i];
            comb(candidate, size, target-candidate[i], i);
            k--;
        }
    } 
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    k = 0;
    ret_size = 0;
    list = malloc(sizeof(int)*200);
    ret_col_size = malloc(sizeof(int)*200);
    ret = malloc(sizeof(int*)*200);
    comb(candidates, candidatesSize, target, 0);
    *returnSize = ret_size;
    *returnColumnSizes = malloc(sizeof(int)*ret_size);
    for(int i = 0;i<ret_size;i++){
        (*returnColumnSizes)[i] = ret_col_size[i];
    }
    free(ret_col_size);
    free(list);
    return ret;
}
