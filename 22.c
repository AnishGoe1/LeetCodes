void process(char** ans, int* idx, char* s, int size, int pos, int left, int right){

    if(left == 0 && right == 0){
        char* t = malloc((size + 1) * sizeof(char));
        t[size] = '\0';
        strcpy(t, s);
        ans[*idx] = t;
        *idx = *idx + 1;
        return;
    }
    if(left == 0){
        s[pos] = ')';
        process(ans, idx, s, size, pos+1, left, right-1);
    }
    else if(left == right){
        s[pos] = '(';
        
        process(ans, idx, s, size, pos+1, left-1, right);
    }
    else{
        s[pos] = ')';
        process(ans, idx, s, size, pos+1, left, right-1);
        
        s[pos] = '(';
        process(ans, idx, s, size, pos+1, left-1, right);
    }
}

char ** generateParenthesis(int n, int* returnSize){

    char** ans = malloc(10000 * sizeof(char*));
    int* idx = calloc(1, sizeof(int));

    int size = 2 * n;
    char* s =  malloc((size + 1) * sizeof(char));
    s[size] = '\0';
    process(ans , idx, s, size, 0, n,  n);
    
    ans = realloc(ans, (*idx)* sizeof(char*));
    * returnSize = *idx;
    free(idx);
    return ans;
}
