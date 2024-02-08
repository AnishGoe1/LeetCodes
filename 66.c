int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for(int i=digitsSize-1;i>=0;i--){
        if(digits[i]<9){
            digits[i]++;
            *returnSize=digitsSize;
            return digits;
        }
        digits[i]=0;
    }
    int* res=(int*)malloc((digitsSize+1)*sizeof(int));
    memset(res,0,(digitsSize+1)*sizeof(int));
    res[0]=1;
    *returnSize=digitsSize+1;
    return res;
}
