int cmpfunc(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

//
//next Permutation
void nextPermutation(char* nums, int numsSize){

    for(int i = numsSize - 2 ; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            qsort(&nums[i+1], numsSize-(i+1), sizeof(char), cmpfunc);
            for(int j = i+1; j < numsSize; j++){
                if(nums[j] > nums[i]){
                    char temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;   
                    return;
                }
            }      
        }
    }
    
    qsort(nums, numsSize, sizeof(char), cmpfunc);
}

char * getPermutation(int n, int k){
    
    char* ans = malloc((n+1) * sizeof(char));
    ans[n] ='\0';
    for(int i = 0; i < n ;i++){
        ans[i] = '1' + i;
    }
    //>>> produce kth number to "char* copy" 
    for(int i = 1; i < k; i++){
        nextPermutation(ans, n);
    }
    //<<<<<
    
    return ans;
}
