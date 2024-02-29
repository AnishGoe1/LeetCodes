/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void pushinterval(int** ans, int* retsize, int** retcolsizes, int lo, int hi) {
    ans[*retsize] = malloc(2 * sizeof(int));
    ans[*retsize][0] = lo;
    ans[*retsize][1] = hi;
    *((*retcolsizes) + *retsize) = 2;
    *retsize = *retsize + 1;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int** ans = malloc((intervalsSize+1) * sizeof(int*));
    *returnColumnSizes = malloc((intervalsSize+1) * sizeof(int));
    
    *returnSize = 0;

    for (int i = 0; i < intervalsSize; ++i) {
        int lo = intervals[i][0];
        int hi = intervals[i][1];

        if (newInterval[1] < lo) {
            pushinterval(ans, returnSize, returnColumnSizes, newInterval[0], newInterval[1]);
            newInterval = intervals[i];
        } else if (newInterval[0] > hi) {
            pushinterval(ans, returnSize, returnColumnSizes, lo, hi);
        } else {
            if (lo < newInterval[0]) {
                newInterval[0] = lo;
            }
            if (hi > newInterval[1]) {
                newInterval[1] = hi;
            }
        }
    }
    pushinterval(ans, returnSize, returnColumnSizes, newInterval[0], newInterval[1]);
    return ans;
}
