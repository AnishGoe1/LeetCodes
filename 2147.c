#define MOD 1000000007
int numberOfWays(char* corridor) {
    long res = 1, j = 0, k = 0, mod = 1e9 + 7;
    int n=strlen(corridor);
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                if (++k > 2 && k % 2 == 1)
                    res = res * (i - j) % mod;
                j = i;
            }
        }
        return k % 2 == 0 && k > 0 ? res : 0;
}
