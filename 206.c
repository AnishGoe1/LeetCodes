/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head) {
        return head;
    }

    int *list = malloc(sizeof(int) * 5001);
    int idx = 0;
    while(!!head) {
        *(list + idx) = head->val;
        idx += 1;
        head = head->next;
    }

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = malloc(sizeof(struct ListNode));
    struct ListNode* next = dummy->next;
    for(int i = idx - 1; i >= 0; i--) {
        next->val = *(list + i);
        if(!i) {
            next->next = NULL;
            continue;
        }

        next->next = malloc(sizeof(struct ListNode));
        next = next->next;
    }

    return dummy->next;
}
