char * makeGood(char * s){
    int n = strlen(s);
    char* ans = malloc((n+1) * sizeof(char));
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(idx == -1){
            idx++;
            ans[idx] = s[i];
        }
        else{
            if(fabs(s[i] - ans[idx]) == 'a' -'A' )
                idx--;
            else{
                idx++;
                ans[idx] = s[i];
            }
                
        }
    }
    idx++;
    ans[idx] = '\0';
    ans = realloc(ans, idx+ 1);
    return ans;
}
