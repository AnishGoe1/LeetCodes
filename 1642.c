#define MAX(a, b) (a) > (b) ? (a) : (b)

int cmp(const void* a, const void* b) {
    return *(const int*) a < *(const int*) b;
}

bool IsOK(int* t, int s, int b, int l) {
    qsort(t, s + 1, sizeof(int), cmp);
    for (int i = l; i <= s; i++) {
        b -= t[i];
        if (b < 0) return false;
    }
    return true;
}

int furthestBuilding(int* h, int n, int bricks, int ladders) {
    int* a = (int*) calloc(n, sizeof(int));
    for (int i = 1; i < n; i++) {
        if (h[i] > h[i-1]) a[i] = h[i] - h[i-1];
    }
    int l = 0, r = n, m = l + ((r - l) >> 1), max = 0;
    int* t = (int*) calloc(n, sizeof(int));
    while (l < r) {
        memcpy(t, a, n * sizeof(int));
        if (IsOK(t, m, bricks, ladders)) {
            max = MAX(m, max);
            l = m + 1;
        } else {
            r = m;
        }
        m = l + ((r - l) >> 1);
    }
    free(a);
    free(t);
    return max;
}
