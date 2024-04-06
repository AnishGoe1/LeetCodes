char * minRemoveToMakeValid(char * s){
    int n = strlen(s);
    bool* flag = calloc(n , sizeof(bool)) ;
    int size = 0;
    int* stack = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[size] = i;
            size++;
        } 
        if (s[i] == ')') {
            if (size > 0) {
                size--;
            }
            else{
                flag[i] = true;
            }
        }
    }
    for(int i = 0; i < size; i++){
        flag[stack[i]] = true;
    }
    char* ans = malloc( (n + 1) * sizeof(char));
    int p = 0;
    for(int i = 0; i < n; i++){
        if(flag[i] == false){
            ans[p] = s[i];
            p++;
        }
    }
    ans[p] = '\0';
    return ans;
}
