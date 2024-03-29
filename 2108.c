char* firstPalindrome(char** words, int wordsSize) {
    char* ans = "";
    for(int i = 0; i < wordsSize; i++) {
        int start = 0, end = strlen(words[i]) - 1;
        while(start < end) {
            if(words[i][start] != words[i][end]) break;
            start++;
            end--;
        }
        if(start == end || end < start) {
            ans = words[i];
            break;
        }
    }
    return ans;
}
