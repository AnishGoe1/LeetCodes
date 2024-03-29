int pivotInteger(int n){
    if(n == 1)
        return 1;
    if(n < 7)
        return -1;
    int sum = (n + 1) * n / 2;
    int cur = 0;
    for(int i = 1; i < n; i++){
        cur += i;
        if((sum - (i+1))%2 == 0 && (sum - (i+1))/2 == cur) 
            return i + 1;
        if((sum - (i+1))/2 < cur)
            return -1;
    }
    return -1;
}
