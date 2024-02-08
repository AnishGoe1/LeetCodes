int numDecodings(char* s) {
    if(strlen(s) == 0 || s[0] == '0'){
        return 0;
    }

    uint32_t dp[strlen(s) + 1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= strlen(s); i++){
        dp[i] = 0;
        int oneDigit = s[i - 1] - 48;
        int twoDigits = (s[i - 1] - 48) + (s[i - 2] - 48) * 10;

        if(oneDigit != 0) {
            dp[i] += dp[i - 1];
        }
        if(10 <= twoDigits && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return (int)dp[strlen(s)];
}
