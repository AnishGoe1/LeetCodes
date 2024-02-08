int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    int counts[arrSize];
	memset(counts, 0, sizeof(counts));
	for (int i = 0; i < arrSize; ++i) {
		if (arrSize > arr[i]) {
			++counts[arr[i]];
		} else {
			++counts[0];
		}
	}
	int ret = 0;
	for (int i = 1; i < arrSize; ++i) {
		if (i - ret < counts[i]) {
			ret += i - ret;
		} else {
			ret += counts[i];
		}
	}
	return ret + counts[0];
}








#define MAX(a, b) ((a) > (b) ? (a) : (b))
int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}
int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    int ans = 1;
    qsort(arr, arrSize, sizeof(int), cmp);
    arr[0] = 1;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < arr[i - 1]) {
            break;
        }
        if (arr[i] - arr[i - 1] > 1) {
            arr[i] = arr[i - 1] + 1;
        }
        ans = MAX(ans, arr[i]);
    }
    return ans;
}

