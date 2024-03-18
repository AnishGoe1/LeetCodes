struct ListNode* deleteDuplicates(struct ListNode* head) {

	if (head == NULL)
		return head;

	struct ListNode* slow = head;
	struct ListNode* fast = head;

	bool isDuplicate = false;

	while (fast != NULL)
	{
		while (fast->next != NULL && fast->val == fast->next->val)
		{
			if (fast == head)
			{
				while (fast->next != NULL && fast->val == fast->next->val)
					fast->next = fast->next->next;
				head = head->next;
			}
			else 
			{
				while (slow != fast && slow->next != fast && slow->next->val != fast->val)
					slow = slow->next;

				fast->next = fast->next->next;
				slow->next = fast->next;
			}
		}

		fast = fast->next;
	}

	return head;
}
