int cmp(const void* a, const void* b) {
    return *(const int*) a - *(const int*) b;
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    if (tokensSize == 0) return 0;
    
    qsort(tokens, tokensSize, sizeof(int), cmp);
    int l = 0, r = tokensSize - 1, cnt = 0;
    while (l < r) {
        if (tokens[l] <= power) {
            power -= tokens[l++];
            cnt++;
        } else {
            if (cnt == 0) break;
            power += tokens[r--];
            cnt--;
        }
    }
    if (tokens[l] <= power) cnt++;
    return cnt;
}
