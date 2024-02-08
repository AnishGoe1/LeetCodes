int maxScore(char* s) {
    int ones = 0,zeros = 0,best = INT_MIN,n=strlen(s);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1') {
            ones++;
        } 
        else {
            zeros++;
        }
        best = fmax(best, zeros - ones);
        }
    if (s[n - 1] == '1') {
        ones++;
    }
    return best + ones; 
}
