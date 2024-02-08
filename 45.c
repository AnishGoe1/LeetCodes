int jump(int* nums, int numsSize) {
    int cur_end = 0, nxt_end = 0, steps = 0;
        for (int i = 0; i < numsSize; i++) {
            if (i > cur_end) steps += 1, cur_end = nxt_end;
            nxt_end = fmax(nxt_end, i + nums[i]);
        }
    return steps;
}
