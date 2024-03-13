long factorial(int n)
{   
    if(n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1) ;
}
void process(int** ans, int* index, int* data, int n, int k, int pos, int cur){
    int i, j;
    if(pos == k){
        for(i = 0; i < k; i++){
            ans[*index][i] = data[i];
        }
        *index = *index + 1;
        return ;
    }
    for(i = cur; i <= n-k+1+ pos; i++){
        data[pos] = i;
        process(ans, index, data, n, k, pos+1, i+1);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int i, j;
    long long int C = 0;
    C = factorial(n) / (factorial(k) * factorial(n - k));
    //printf("C %d?%d = %lld\n", n, k, C);
    
    *returnColumnSizes = (int*)malloc(C * sizeof(int));
    * returnSize = C;
    int** ans = (int**)malloc(C * sizeof(int*));
    for(i = 0; i < C; i++){
        ans[i] = (int*)calloc(k , sizeof(int)); 
        returnColumnSizes[0][i] = k;
    }
    int* data = (int*)malloc(k * sizeof(int));

    int* index = (int*)malloc(sizeof(int));
    *index = 0;
    process(ans, index, data, n, k,0 ,1);
    free(data);
    free(index);
    return ans;
}
