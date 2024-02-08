#define MOD 1000000007

int knightDialer(int n) {
    long long cur_pos[10];
    for (int i = 0; i < 10; ++i) {
        cur_pos[i] = 1;
    }
    for (int jump = 2; jump <= n; ++jump) {
        long long new_pos[10] = {0};
        new_pos[0] = (cur_pos[6] + cur_pos[4]) % MOD;
        new_pos[1] = (cur_pos[6] + cur_pos[8]) % MOD;
        new_pos[2] = (cur_pos[7] + cur_pos[9]) % MOD;
        new_pos[3] = (cur_pos[4] + cur_pos[8]) % MOD;
        new_pos[4] = (cur_pos[0] + cur_pos[3] + cur_pos[9]) % MOD;
        new_pos[5] = 0;
        new_pos[6] = (cur_pos[0] + cur_pos[1] + cur_pos[7]) % MOD;
        new_pos[7] = (cur_pos[2] + cur_pos[6]) % MOD;
        new_pos[8] = (cur_pos[1] + cur_pos[3]) % MOD;
        new_pos[9] = (cur_pos[2] + cur_pos[4]) % MOD;
        for (int i = 0; i < 10; ++i) {
            cur_pos[i] = new_pos[i];
        }
    }
    long long total_count = 0;
    for (int i = 0; i < 10; ++i) {
        total_count = (total_count + cur_pos[i]) % MOD;
    }

    return (int)total_count;
}
