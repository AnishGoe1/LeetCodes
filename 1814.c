int rev(int n) {
    int m = 0;
    while (n) {
        m *= 10;
        m += n % 10;
        n /= 10;
    }
    return m;
}

struct Pair {
    int isDefined;
    int key;
    int val;
};

int countNicePairs(int* nums, int numsSize) {
    int n = numsSize;
    struct Pair *hash = calloc(n, sizeof(struct Pair)); 
    for (int i = 0; i < n; ++i) {
        int diff = nums[i] - rev(nums[i]);
        int j = diff % n + n;
        while (hash[j % n].isDefined && hash[j % n].key != diff) j += 1;
        hash[j % n].isDefined = 1;
        hash[j % n].key = diff;
        hash[j % n].val += 1;
    }
    long count = 0;
    for (int i = 0; i < n; ++i) {
        long m = hash[i].val;
        count += m * (m - 1) / 2;
        count %= 1000000007;
    }
    free(hash);
    return count;
}
