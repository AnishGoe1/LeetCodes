int SubarraysWithLessEqualKDiffIntegers(int* nums, int n, int k){
    int ans = 0;
    int** hash = calloc(n ,sizeof(int*));

    int r = 0, l = 0;
    int type = 0;
    for(r = 0; r < n; r++){
        int d = nums[r];
        while(1){
            if(hash[d % n] == NULL){
                hash[d% n] = malloc(2 * sizeof(int));
                hash[d% n][0] = nums[r];
                hash[d% n][1] = 1;
                type++;
                break;
            }
            else{
                if(hash[d%n][0] == nums[r]){
                    hash[d%n][1]++;
                    break;
                }
                d++;
            }
        }
        while(type > k){
            d = nums[l];
            while(1){
                if(hash[d%n] && hash[d%n][0] == nums[l]){
                    hash[d%n][1]--;
                    if(hash[d%n][1] == 0){
                        type--;
                        free(hash[d%n]);
                        hash[d%n] = NULL;
                    }
                    break;
                }
                else
                    d++;  
            }
            l++;
        }
        ans += r - l + 1 ;
    }
    return ans;
}

int subarraysWithKDistinct(int* nums, int numsSize, int k){
    return SubarraysWithLessEqualKDiffIntegers(nums, numsSize, k) - SubarraysWithLessEqualKDiffIntegers(nums, numsSize, k-1);
}
