#define KEY_SIZE    50

typedef struct {
    char *diffStr;      // long long stored as string key
    int sum;
    UT_hash_handle hh;
} hElem;

int numberOfArithmeticSlices(int* nums, int numsSize) {
    // array of hashmaps
    hElem **count = calloc(sizeof(hElem *), numsSize), *t;
    long long result = 0, diff = 0;
    
    for(int i = 1; i < numsSize; i++) {
        count[i] = NULL;
        for(int j = 0; j < i; j++) {
            diff = (long long)nums[i] - (long long)nums[j];
            int sum = 0, origin = 0;
            
            // form string key from diff
            char *diffStr = calloc(sizeof(char), KEY_SIZE + 1);
            sprintf(diffStr, "%lld", diff);
            HASH_FIND_STR(count[j], diffStr, t);
            if(t) {
                sum = t->sum;
            } 
            
            HASH_FIND_STR(count[i], diffStr, t);
            if(t) {
                t->sum += sum + 1;                
            } else {
                t = calloc(sizeof(hElem), 1);
                t->diffStr = diffStr; t->sum = sum+1;
                HASH_ADD_STR(count[i], diffStr, t);
            }
            result += sum;
        }
        
    }
    return result;
}
    
