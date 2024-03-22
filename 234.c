bool isPalindrome(struct ListNode* head) {

	if (head == NULL) return true;

	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	struct ListNode* temp = slow;
	int arr[100000];
	int index = 0;
	while (temp != NULL)
	{
		arr[index] = temp->val;
		temp = temp->next;
		index++;
	}

	struct ListNode* start = head;
	while (start != slow && (index - 1) >= 0)
	{
		if (start->val != arr[index - 1])
			return false;
		index--;
		start = start->next;
	}

	return true;
}
