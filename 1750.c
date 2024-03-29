int minimumLength(char * s){
    int n = strlen(s) ;
    int left = 0, right = n-1 ;
    while(left < n && right > left && s[left] == s[right]){
        char ch = s[left] ;
        while(s[left] == ch)
            left++ ;
        while(right > left && s[right] == ch)
            right-- ;
    }
    return right - left + 1 ;
}
