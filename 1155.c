#define MOD 1000000007

int get_ways_to_target(int **memo, int dice_idx, const int *n, int curr_sum, const int *target, const int *k) {
    /* All the n dice are traversed, the sum must be equal to target for valid combination */
    if (dice_idx == *n) {
        return curr_sum == *target;
    }

    /* If we have already calculated the anser, use the previous result */
    if (memo[dice_idx][curr_sum] != -1) {
        return memo[dice_idx][curr_sum];
    }

    /* Iterate over the possible face value for current dice */
    int ways = 0;
    for (int i = 1; i <= fmin(*k, *target - curr_sum); ++i) {
        ways = (ways + get_ways_to_target(memo, dice_idx + 1, n, curr_sum + i, target, k)) % MOD;
    }

    /* Update memo and return the result */
    return memo[dice_idx][curr_sum] = ways;
}

int numRollsToTarget(int n, int k, int target) {
    /* Allocate memory */
    int **memo = (int **)calloc(n + 1, sizeof(int *));
    if (memo == NULL) {
        fprintf(stderr, "Memory allocation failure");
        free(memo);
        return -1;
    }

    for (int i = 0; i <= n; ++i) {
        memo[i] = (int *)malloc((target + 1) * sizeof(int));
        if (memo[i] == NULL) {
            fprintf(stderr, "Memory allocation failure");
            for (int j = 0; j <= i; ++j) {
                free(memo[j]);
            }
            free(memo);
            return -1;
        }

        for (int j = 0; j <= target; ++j) {
            memo[i][j] = -1;
        }
    }

    int result = get_ways_to_target(memo, 0, &n, 0, &target, &k);

    /* Release memory space */
    for (int i = 0; i < n + 1; ++i) {
        free(memo[i]);
    }
    free(memo);

    return result;
}
