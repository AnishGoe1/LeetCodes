typedef struct {
    int val;
    int freq;
    UT_hash_handle hh;
} Node1;

int cmp(const void *a, const void *b) {
    Node1 *a1 = (Node1 *)a;
    Node1 *b1 = (Node1 *)b;
    
    return b1->freq - a1->freq;
}

char * frequencySort(char * s){
    Node1 *ht = NULL;
    int len = strlen(s);
    
    for (int i=0; i<len; i++) {
        Node1 *tmp = NULL;
        int c = (int)s[i];
        HASH_FIND_INT(ht, &c, tmp);
        if (tmp) {
            tmp->freq++;
        } else {
            tmp = (Node1 *)malloc(sizeof(Node1));
            memset(tmp, 0, sizeof(Node1));
            tmp->val = s[i];
            tmp->freq = 1;
            HASH_ADD_INT(ht, val, tmp);
        }
    }
    
    HASH_SORT(ht, cmp);
    
    Node1 *iter, *t;
    char *ans = (char *)malloc(sizeof(char) * (len+1));
    int pos = 0;
    memset(ans, 0, sizeof(char) * (len+1));
    HASH_ITER(hh, ht, iter, t) {
        for (int i=0; i<iter->freq; i++) {
            ans[pos++] = (char)iter->val;
        }
        HASH_DEL(ht, iter);
        free(iter);
    }
    
    return ans;
}
