#pragma GCC optimize("O3")
int reductionOperations(int* nums, int n) {
    int freq[50001]={0};
    int minN=50000, maxN=0;
    #pragma unroll
    for(register int i=0; i<n; i++){
        int x=nums[i];
        freq[x]++;
        if (x<minN) minN=x;
        if (x>maxN) maxN=x;
    }
    int count=0, sum=0;
    #pragma unroll
    for(register int x=maxN; x>minN; x--){
        if (freq[x]>0){
            sum+=freq[x];
            count+=sum;
        }
    }
    return count;
}
