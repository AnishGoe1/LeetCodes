char * removeKdigits(char * num, int k){
    int n = strlen(num) ;
    if(k >= n)
        return "0" ;
    int* stk = malloc(n * sizeof(int) ) ;
    stk[0] = 0 ;
    int s_idx = 1 ;
    
    for(int i = 1 ; i < n; i++){
        if(k == 0){
            stk[s_idx] = i ;
            s_idx++ ;
            continue ;
        }
        while(s_idx > 0 && num[i] < num[stk[s_idx-1]] ){
            s_idx-- ;
            k-- ;
            if(k == 0)
                break ;
        }
        stk[s_idx] = i ;
        s_idx++ ;        
    }

    int i = 0 ;
    int a_idx = 0 ;
    s_idx -= k ;
    char* ans = malloc(s_idx+1) ;
    for(i = 0; i < s_idx; i++){        
        if(num[stk[i]] != '0')
            break ;
    }

    for(int j = i; j < s_idx; j++){
        ans[a_idx] = num[stk[j]] ;
        a_idx++ ;
    }
    ans[a_idx] = '\0' ;
    if(a_idx == 0)
        return "0" ;
    return ans ;
}
