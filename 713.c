

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int i, j;
    int n  =  numsSize;

    int prod;
    int ans = 0;
    int line ;
    for(i = 0; i < n; i++){
        line = 0;
        for(j = i; j < n; j++){
            if(i == j){
                prod = nums[i];
                if(prod < k){
                    line++;
                    continue;
                }
                else
                    break;
            }
            else{
                prod *= nums[j];            
                if(prod < k)
                    line++; 
                else
                    break;
            }           
        }
        if(line == n-i){
            break;
        }
        else
            ans += line;
    }
    for(int m = line; m >=0; m--){
        ans += m;
    }
    return ans;

}
