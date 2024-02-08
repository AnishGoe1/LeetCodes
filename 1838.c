#pragma GCC optimize("O3")
int freq[100001]={0};
void freqSort(int* nums, int n){
    memset(freq, 0, sizeof(freq));
    int M=0;
    #pragma unroll
    for(register int i=0; i<n; i++){
        int x=nums[i];
        freq[x]++;
        if (x>M) M=x;
    }
    int i=0;
    #pragma unroll
    for(register int x=1; x<=M; x++){
        while(freq[x]-->0){
            nums[i++]=x;
        }
    }
}
int maxFrequency(int* nums, int n, int k) {
    freqSort(nums, n);
    int Freq=0, l=0;
    long long sum=0;
    #pragma unroll
    for(register int r=0; r<n; r++){
        long long x=nums[r];
        sum+=x;
        #pragma unroll
        while((r-l+1)*x-sum>k)
            sum-=nums[l++]; 
        if (Freq<r-l+1)Freq=r-l+1;
    }       
    return Freq;
}
