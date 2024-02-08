#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct idx{
    int leftmost;
    int rightmost;
} idx_t;
idx_t hash[26];
bool subseq[26][26];
int countPalindromicSubsequence(char* s) {
    int len = strlen(s), ans = 0;
    memset((void *)subseq, 0, sizeof(subseq));
    for (int i = 0; i < 26; i++) {
        hash[i].leftmost = INT_MAX;
        hash[i].rightmost = INT_MIN;
    }
    for (int i = 0; i < len; i++) {
        hash[s[i] - 'a'].leftmost = MIN(hash[s[i] - 'a'].leftmost, i);
        hash[s[i] - 'a'].rightmost = MAX(hash[s[i] - 'a'].rightmost, i);
    }
    for (int i = 0; s[i]; i++) {
        int left = hash[s[i] - 'a'].leftmost;
        int right = hash[s[i] - 'a'].rightmost;
        if (left != INT_MAX && right != INT_MIN) {
            hash[s[i] - 'a'].leftmost = INT_MAX;
            hash[s[i] - 'a'].rightmost = INT_MIN;
            for (int j = left + 1; j < right; j++) {
                if (subseq[s[i] - 'a'][s[j] - 'a'] == false) {
                    subseq[s[i] - 'a'][s[j] - 'a'] = true;
                    ans++;
                }
            }
        }
    }
    return ans;
}
