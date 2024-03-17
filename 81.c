int findmin(int* nums, int numsSize) {
    int minidx = 0;
    for(int i = 0; i+1 < numsSize; i++) {
        if(nums[i+1] < nums[i]) {
            minidx = i+1;
            break;
        }
    }
    return minidx;
}

bool search(int* nums, int numsSize, int target) {
    if(numsSize == 1) return nums[0] == target ? true : false;
    
    int start = findmin(nums, numsSize), end = start + numsSize;
    int arrSize = 2 * numsSize;
    int* arr = (int*) malloc(arrSize * sizeof(int));
    for(int i = 0; i < arrSize; i++) {
        arr[i] = nums[i % numsSize];
    }
    bool Isfind = false;
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(target == arr[mid]) {
            Isfind = true;
            break;
        } else if(target < arr[mid]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    free(arr);
    return Isfind;
}
