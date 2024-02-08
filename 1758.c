int minOperations(char* s) {
    int n = strlen(s), count = 0;;
        if(n == 1) return 0;
        for(int i = 0; i < n; i++) {
            if(i%2 == 0 && s[i] == '1') count++;
            if(i%2 == 1 && s[i] == '0') count++;
        }
    return fmin(count, n-count); 
}
