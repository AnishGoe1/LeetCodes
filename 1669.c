struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {

	if (list1 == NULL)
		return list2;

	if (list2 == NULL)
		return list1;

	struct ListNode* start = list1;
	struct ListNode* end = list1;

	int index = 0;
	while (index < a - 1)
	{
		start = start->next;
		index++;
	}

	index = 0;
	while (index < b + 1)
	{
		end = end->next;
		index++;
	}

	start->next = list2;

	struct ListNode* travel = list2;

	while (travel->next != NULL)
		travel = travel->next;

	travel->next = end;

	return list1;
}
