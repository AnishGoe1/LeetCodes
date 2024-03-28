typedef struct {
    UT_hash_handle hh;
    int num;
    int cnt;
} hElem;

int maxSubarrayLength(int* nums, int numsSize, int k) {
    hElem *freq = NULL, *t, *s;
    int left = 0, moreThanK = 0;
    
    for(int right = 0; right < numsSize; right++) {
        HASH_FIND_INT(freq, &nums[right], t);
        if(t) {
            t->cnt++;
        } else {
            t = calloc(sizeof(hElem), 1);
            t->num = nums[right]; t->cnt = 1;
            HASH_ADD_INT(freq, num, t);
        }
        
        if(t->cnt == k+1)
            moreThanK++;
        
        if(moreThanK > 0) {
            HASH_FIND_INT(freq, &nums[left], s);
            s->cnt--;
            if(s->cnt == k) {
                moreThanK--;
            }
            left++;
        }
    }
    return numsSize - left;
}
