bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            int numRepeats = n / i;
            char substring[i + 1];
            strncpy(substring, s, i);
            substring[i] = '\0';
            char repeatedString[n + 1];
            repeatedString[0] = '\0';
            for (int j = 0; j < numRepeats; j++) {
                strcat(repeatedString, substring);
            }
            if (strcmp(repeatedString, s) == 0) {
                return true;
            }
        }
    }
    return false;
}
