#define MINV -100000
#define MAXV 100000
#define RANGEV (MAXV - MINV + 1u)
typedef unsigned long long u64;
static u64 eindex[RANGEV];
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FORCE __attribute__((always_inline)) inline
static FORCE unsigned lo(const u64 p) {
    return p & UINT_MAX;
}
static FORCE unsigned hi(const u64 p) {
    return p >> 32;
}
static FORCE void addp(u64 *p, const unsigned i) {
    *p += (u64)i << ((*p != 0) << 5);
}
static FORCE void removep(u64 *p, const unsigned i) {
    if (lo(*p) == i) *p = hi(*p);
    else if (hi(*p) == i) *p = lo(*p);
}
int* restoreArray(int*const*const apairs, const unsigned n, const int* const ncol, int* const rsize) {
    if (n == 1) {
        int *r = malloc(2 * sizeof(int));
        memcpy(r, *apairs, 2 * sizeof(int));
        *rsize = 2;
        return r;
    }
    int minv = MAXV, maxv = MINV;
    for (unsigned i = 0; i < n; i++) {
        const int *ap = apairs[i];
        const int v0 = ap[0], v1 = ap[1];
        addp(eindex+v0-MINV, i + 1);
        addp(eindex+v1-MINV, i + 1);
        const int mn = MIN(v0, v1);
        const int mx = MAX(v0, v1);
        minv = MIN(mn, minv);
        maxv = MAX(mx, maxv);
    }
    int head = minv;
    while (head <= maxv && eindex[head-MINV] - 1u >= UINT_MAX)
        head++;
    int *const r = malloc((n + 1u) * sizeof(int));
    *r = head;
    unsigned i = 1;
    for (u64 idx = eindex[head-MINV]; idx; idx = eindex[head-MINV]) {
        const int *ap = apairs[lo(idx) - 1];
        eindex[head-MINV] >>= 32;
        removep(eindex+head-MINV, lo(idx));
        r[i++] = head = ap[ap[0] == head];
        removep(eindex+head-MINV, lo(idx));
    }
    *rsize = i;
    return r;
}
