void reverse(struct ListNode** data , int begin, int end){
    struct ListNode* temp;
    int Begin = begin, End = end;
    while(Begin < End){
        temp = data[Begin];
        data[Begin] = data[End];
        data[End] = temp;
        Begin++;
        End--;
    }
    for(int i = begin; i < end; i++){
        data[i]->next = data[i+1];
    }
//    data[end]->next = NULL;
}

int getListSize(struct ListNode* head){
    struct ListNode* temp = head;
    int ans = 0;
    while(temp){
        ans++;
        temp = temp->next;
    }
    return ans;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int ListSize =  getListSize(head); 
    struct ListNode** data = malloc(ListSize * sizeof(struct ListNode* ));
    struct ListNode* temp = head;
    for(int i = 0; i < ListSize; i++){
        data[i] = temp;
        temp = temp->next;
    }
    int begin , end;
    struct ListNode* mid;
    for(int i = 0; i < (ListSize/k); i++){
        begin = k*i;
        end = begin + k - 1;
        while(begin < end){
            mid = data[begin];
            data[begin] = data[end];
            data[end] = mid;
            begin++;
            end--;
        }
    }
    for(int i = 0; i < (ListSize-1); i++){
        data[i]->next = data[i+1];
    }
    data[ListSize-1]->next = NULL;
    return data[0];
}
