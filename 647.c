int countSubstrings(char * s){
    
    int i = 0;
    int num = 0;
    int left = 0;
    int right = 0;
    
    while (s[i] != '\0') {
        left = i;
        right = i;
        while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
            num++;
            left --;
            right ++;
        }
        
        left = i;
        right = i+1;
        while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
            num++;
            left --;
            right++;
        }
        i++;
    }
    
    return num;
}
