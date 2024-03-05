int GetLength(struct ListNode* head)
{
	if (head == NULL)
		return 0;

	return 1 + GetLength(head->next);
}

struct ListNode* rotateRight(struct ListNode* head, int k) {

	if (head == NULL || k == 0)
		return head;

	int length = GetLength(head);

	if (length == 1)
		return head;

	if (k > length)
	{
		int t = k / length;
		k = k - (t * length);
	}

	while (k > 0)
	{
		int tempLength = length;
		struct ListNode* secondLastNode = head;
		while (tempLength - 2 > 0)
		{
			secondLastNode = secondLastNode->next;
			tempLength--;
		}
		secondLastNode->next->next = head;
		head = secondLastNode->next;
		secondLastNode->next = NULL;
		k--;
	}
	return head;
}
