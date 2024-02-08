#define max(a, b) ((a > b) ? a : b)

int longestValidParentheses(char* s) {
    int len = strlen(s);
    int* stack = malloc(sizeof(int) * (len + 1));
    *stack = -1;
    int stack_len = 1;
    int res = 0;

   for(int idx = 0; idx < len; idx++) {
        if(*(s + idx) == ')') {
            stack_len--;
            if(stack_len < 0) {
                stack_len = 0;
            }

            if(stack_len == 0) {
                *(stack + stack_len) = idx;
                stack_len++;
            } else {
                res = max(res, (idx - *(stack + stack_len - 1)));
            }
        } else {
            *(stack + stack_len) = idx;
            stack_len++;
        }
    }

    free(stack);

    return res;
}
