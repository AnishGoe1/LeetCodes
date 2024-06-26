//struct ListNode {
//      int val;
//      struct ListNode *next;
// };

typedef struct ListNode LNode;

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

//list save index, do the following steps repeatedly until all cards are revealed
//final list will be the index sequence
//sort deck, iterate list's val, save deck[i] data to ans[list's val]
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
    LNode* head = malloc(sizeof(LNode));
    head->val = 0;
    LNode* temp = head;
    
    for(int i = 1; i < deckSize; i++){
        LNode* node = malloc(sizeof(LNode));
        node->val = i;
        temp->next = node;
        temp = node;
    }
    LNode* tail = temp;
    tail->next = NULL;
    
    temp = head;
    LNode* post;
    while(temp->next && temp->next->next ){
        post = temp->next;
        temp->next = temp->next->next;
        tail->next = post;
        tail = post;
        tail->next = NULL;
        temp = temp->next;
    }

    int* ans = malloc(deckSize * sizeof(int));
    qsort(deck, deckSize, sizeof(int), cmpfunc);

    temp = head;
    LNode* ptr;
    for(int i = 0; i < deckSize; i++){
        ans[temp->val] = deck[i];
        ptr = temp;
        temp = temp->next;
        free(ptr);
    }
    *returnSize = deckSize;
    return ans;
}
