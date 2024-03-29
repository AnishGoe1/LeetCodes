struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* temp = head;
    struct ListNode* min;
    int id;    
    while(1){
        min = lists[0];
        id = 0;
        for(int i = 1; i < listsSize; i++){
            if(min == NULL && lists[i]){
                min = lists[i];
                id = i;
            }
            if(lists[i] == NULL)
                continue;
            else{
                if(lists[i]->val < min->val){
                    min = lists[i];
                    id = i;
                }
            }
        }
        if(min == NULL){
            temp->next = NULL;
            break;
        }
        temp->next = min;
        temp = temp->next;
        lists[id] = lists[id]->next;
        while(lists[id] && lists[id]->val == temp->val){
            temp->next = lists[id];
            temp = temp->next;
            lists[id] = lists[id]->next;
        }
    }
    return head->next;
}
