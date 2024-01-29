int expandAroundCenter(char *s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char *s) {
    if (s == NULL || strlen(s) < 1) return "";

    int start = 0, end = 0;
    for (int i = 0; i < strlen(s); i++) {
        int len1 = expandAroundCenter(s, i, i);    // For odd length palindromes
        int len2 = expandAroundCenter(s, i, i + 1); // For even length palindromes
        int len = len1 > len2 ? len1 : len2;

        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    
    char *result = malloc((end - start + 2) * sizeof(char));
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';

    return result;
}
