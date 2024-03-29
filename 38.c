char* IntToChar(int n){
    char* ans = malloc(11);
    ans[10] = '\0';
    int idx = 9;
    while(n){
        ans[idx] = '0' + n%10;
        n /= 10;
        idx--;
    }    
    return &ans[idx+1];
}

char * countAndSay(int n){
    //5000 is estimated by test case 
    char* cur = malloc(5000 );
    char* post = malloc(5000);
    cur[0] = '1';
    cur[1] = '\0';
     post;
    if(n == 1)
        return cur;
    
    for(int i = 2; i <= n; i++){
        int len_cur = strlen(cur);
        int idx = 0;
        int cn = 1;
        int pos = 0;
        char* temp;
        for(int j = 1; j < len_cur; j++){
            if(cur[j] == cur[j-1])
                cn++;
            else{
                temp = IntToChar(cn);
                strncpy(&post[pos] , temp, strlen(temp));
                pos += strlen(temp);
                post[pos] = cur[j-1];
                pos++;
                cn = 1;
            }                
        }
        temp = IntToChar(cn);
        strncpy(&post[pos] , temp, strlen(temp)); 
        pos += strlen(temp);
        post[pos] = cur[len_cur-1];
        pos++;
        post[pos] = '\0';
        temp = cur;
        cur = post;
        post = temp;
    }
    return cur;
    
}
