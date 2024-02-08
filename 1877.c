#pragma GCC optimize("O3")

int minPairSum(int* nums, int n){
    int freq[100001]={0};
    int l=100000, r=1;
    #pragma unroll
    for(register i=0; i<n; i++){
        int x=nums[i];
        freq[x]++;
        if (l>x) l=x;
        if (r<x) r=x;
    }
    int maxP=0, rN=0, lN=0, k=n>>1;
    #pragma unroll
    for(register int pairN=1; pairN<=k; pairN++){
        #pragma unroll
        while (lN < pairN) lN += freq[l++];
            
        #pragma unroll
        while (rN < pairN) rN += freq[r--];
        if (l+r>maxP) maxP=l+r;
    }
    return maxP;
}
