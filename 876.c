struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *current;
    int c=0, i;
    for(current=head;current!=NULL;current = current->next, c++);
    c/=2;
    for(i=0, current=head;i<c;i++, current=current->next);
    return current;
}
