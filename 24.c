struct ListNode* swapPairs(struct ListNode* head) {

	struct ListNode* first = head;
	struct ListNode* prev = NULL;

	int firstTime = 1;
	while (first != NULL && first->next != NULL)
	{
		struct ListNode* second = first->next;
		struct ListNode* third = second->next;

		if (prev != NULL) prev->next = second;

		second->next = first;
		first->next = third;

		if (firstTime == 1)
			head = second;

		firstTime = 0;
		prev = first;
		first = first->next;
	}

	return head;
}

