#define MAX(a, b) ((a)>(b)?(a):(b))

int maxSubArray(int* nums, int numsSize)
{
    int i;
    int best = INT_MIN;
    int currsum = 0;

    for (i = 0; i < numsSize; i++) {
        currsum = MAX(currsum + nums[i], nums[i]);
        best = MAX(best, currsum);
    }

    return best;
}
